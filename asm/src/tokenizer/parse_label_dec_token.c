/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_label_dec_token.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

char *get_label_dec_value(char const *str, int start_pos, int length)
{
    char *label = malloc(sizeof(char) * length);

    CHECK_MALLOC(label);
    m_strncpy(label, str + start_pos, length - 1);
    return label;
}

bool check_label_dec(tokenizer_t *this)
{
    int i = 0;

    skip_white_spaces(this);
    i = this->data_pos;
    while (this->info_tokens[this->curr_line]->db.buffer[i] != LABEL_CHAR) {
        if (!str_contains(LABEL_CHARS, this->info_tokens[this->curr_line]
        ->db.buffer[i]))
            return false;
        i++;
    }
    return true;
}

bool parse_label_dec(tokenizer_t *this)
{
    int i = this->data_pos;
    int curr_token = this->info_tokens[this->curr_line]->curr_token;

    while (this->info_tokens[this->curr_line]->db.buffer[i] != LABEL_CHAR) {
        if (!str_contains(LABEL_CHARS, this->info_tokens[this->curr_line]
        ->db.buffer[i]))
            return false;
        i++;
    }
    i++;
    this->info_tokens[this->curr_line]->token_type[curr_token] = LBL_OPT_TOKEN;
    this->info_tokens[this->curr_line]->token_length[curr_token] =
    i - this->data_pos;
    this->info_tokens[this->curr_line]->str_v[curr_token] =
    get_label_dec_value(this->info_tokens[this->curr_line]->db.buffer,
    this->data_pos, i - this->data_pos);
    this->data_pos += (i - this->data_pos);
    return true;
}