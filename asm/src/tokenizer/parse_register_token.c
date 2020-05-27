/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_register_token.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

bool is_num_remaining(char const *str, int *length)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != SEPARATOR_CHAR && !is_space(str[i]); i++)
        if (!is_num(str[i])) {
            *length = -1;
            return false;
        }
    *length = i;
    return true;
}

int parse_register_token(tokenizer_t *this)
{
    int nb_len = 0, tmp = this->data_pos, reg_num = 0;

    tmp++;
    CHECK_FALSE(is_num_remaining(
            this->info_tokens[this->curr_line]->db.buffer + tmp
            , &nb_len
        )
    )
    reg_num = m_getnbr(this->info_tokens[this->curr_line]->db.buffer + tmp);
    CHECK_FALSE(reg_num < REG_NUMBER + 1 && reg_num > 0)
    this->info_tokens[this->curr_line]
    ->token_type[this->info_tokens[this->curr_line]->curr_token] = REG_TOKEN;
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token] = nb_len + 1;
    this->info_tokens[this->curr_line]
    ->nbr_v[this->info_tokens[this->curr_line]->curr_token] = reg_num;
    return EXEC_SUCCESS;
}