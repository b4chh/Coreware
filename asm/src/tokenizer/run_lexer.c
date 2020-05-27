/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** run_lexer.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int analyze_line(tokenizer_t *this)
{
    skip_white_spaces(this);
    if (parse_label_dec(this)) {
        CHECK_ERR(eat_space(this));
        this->info_tokens[this->curr_line]->curr_token++;
    }
    CHECK_TRUE(!this->info_tokens[this->curr_line]->db.buffer[this->data_pos])
    CHECK_ERR(parse_instruction_token(this));
    if (check_label_dec(this)) {
        this->info_tokens[this->curr_line]->curr_token++;
        parse_label_dec(this);
        CHECK_ERR(check_end(this));
    }
    return EXEC_SUCCESS;
}

int run_lexer(tokenizer_t *this)
{
    CHECK_ERR(get_header_info(this));
    for (int i = 0; i < this->nb_lines; i++) {
        if (empty_string(this->info_tokens[i]->db.buffer) ||
        is_valid_cmd(this->info_tokens[i]->db.buffer)) {
            this->curr_line++;
            continue;
        }
        CHECK_ERR(analyze_line(this));
        this->data_pos = 0;
        this->curr_line++;
    }
    return EXEC_SUCCESS;
}