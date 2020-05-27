/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_indirect_value.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int parse_indirect_value(tokenizer_t *this)
{
    char *buffer = this->info_tokens[this->curr_line]->db.buffer;
    int len = 0;

    CHECK_FALSE(
        is_num_remaining(
                buffer + this->data_pos,
                &len
        )
    )
    this->info_tokens[this->curr_line]
    ->token_type[this->info_tokens[this->curr_line]->curr_token] = IND_TOKEN;
    this->info_tokens[this->curr_line]
    ->nbr_v[this->info_tokens[this->curr_line]->curr_token] =
    m_getnbr(buffer + this->data_pos);
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token] = len;
    return EXEC_SUCCESS;
}
