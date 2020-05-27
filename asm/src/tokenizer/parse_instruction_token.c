/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_instruction_token.c
*/

#include "utils.h"
#include "asm.h"

static int parse_token(tokenizer_t *this)
{
    int i = 0;

    for (i = 0; i < NB_TOKENS; i++) {
        if (str_contains(
                TOKEN_OPS[i].str,
                this->info_tokens[this->curr_line]->db.buffer[this->data_pos]
            )
        )
            CHECK_SUCCESS(TOKEN_OPS[i].callback(this));
    }
    return EXEC_FAIL;
}

int get_next_token(tokenizer_t *this)
{
    this->info_tokens[this->curr_line]->curr_token += 1;
    CHECK_ERR(parse_token(this))
    this->data_pos +=
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token];
    skip_white_spaces(this);
    CHECK_ERR(eat_comma(this))
    return EXEC_SUCCESS;
}

int parse_instruction_token(tokenizer_t *this)
{
    parse_token(this);
    CHECK_FALSE(this->info_tokens[this->curr_line]
    ->token_type[this->info_tokens[this->curr_line]->curr_token] == MNE_TOKEN)
    this->data_pos +=
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token];
    CHECK_ERR(eat_space(this));
    while (this->info_tokens[this->curr_line]->db.buffer[this->data_pos] &&
    !check_label_dec(this))
        CHECK_ERR(get_next_token(this))
    return EXEC_SUCCESS;
}