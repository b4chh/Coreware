/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_mnemonic_token.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

static int get_length_mnemonic(char const *str)
{
    int i = 0;

    for (i = 0; str[i] && !is_space(str[i]); i++);
    return i;
}

static bool is_operation(char const *str, int *length, char **buffer)
{
    int i = 0;

    for (i = 0; i < NB_OPERATIONS; i++) {
        if (m_strncmp(OPERATIONS[i].name, str, m_strlen(OPERATIONS[i].name))
        == 0 && get_length_mnemonic(str) == OPERATIONS[i].length_token) {
            *length = OPERATIONS[i].length_token;
            *buffer = m_strdup(OPERATIONS[i].name);
            return true;
        }
    }
    return false;
}

int parse_mnemonic_token(tokenizer_t *this)
{
    int token_len = 0;
    char *buffer = NULL;

    CHECK_FALSE(is_operation(this->info_tokens[this->curr_line]->db.buffer
    + this->data_pos, &token_len, &buffer));
    this->info_tokens[this->curr_line]
    ->token_type[this->info_tokens[this->curr_line]->curr_token] = MNE_TOKEN;
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token] = token_len;
    this->info_tokens[this->curr_line]
    ->str_v[this->info_tokens[this->curr_line]->curr_token] = buffer;
    return EXEC_SUCCESS;
}