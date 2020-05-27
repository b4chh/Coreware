/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** eat_comma.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

int eat_comma(tokenizer_t *this)
{
    skip_white_spaces(this);
    if (this->info_tokens[this->curr_line]->db.buffer[this->data_pos] != ',') {
        if (!this->info_tokens[this->curr_line]->db.buffer[this->data_pos]
        || check_label_dec(this))
            return EXEC_SUCCESS;
        return EXEC_FAIL;
    }
    this->data_pos++;
    skip_white_spaces(this);
    return EXEC_SUCCESS;
}

int eat_space(tokenizer_t *this)
{
    if (this->info_tokens[this->curr_line]->db.buffer[this->data_pos] == '\0')
        return EXEC_SUCCESS;
    if (!is_space(
            this->info_tokens[this->curr_line]->db.buffer[this->data_pos]
        )
    )
        return EXEC_FAIL;
    this->data_pos++;
    skip_white_spaces(this);
    return EXEC_SUCCESS;
}

int check_end(tokenizer_t *this)
{
    skip_white_spaces(this);
    if (this->info_tokens[this->curr_line]->db.buffer[this->data_pos] == '\0')
        return EXEC_SUCCESS;
    return EXEC_FAIL;
}

bool is_space(char c)
{
    return c == ' ' || c == '\r' || c == '\t';
}