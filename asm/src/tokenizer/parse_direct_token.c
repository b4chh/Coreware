/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parse_direct_token.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int get_label_value(char const *str, int *start_pos, char **buffer)
{
    int len = 0;

    (*start_pos)++;
    for (len = 0; str[*start_pos + len]
    && str[*start_pos + len] != SEPARATOR_CHAR
    && !is_space(str[*start_pos + len]); len++)
        CHECK_FALSE(str_contains(LABEL_CHARS, str[*start_pos + len]))
    *buffer = malloc(sizeof(char) * (len + 1));
    CHECK_NULL(*buffer)
    m_memset(*buffer, '\0', len + 1);
    m_strncpy(*buffer, str + *start_pos, len);
    *start_pos += len;
    return EXEC_SUCCESS;
}

static int get_direct_value(tokenizer_t *this, char const *str, int *tmp_pos)
{
    int nb_len = 0;
    char *label = NULL;

    if (str[*tmp_pos] == LABEL_CHAR) {
        CHECK_ERR(get_label_value(str, tmp_pos, &label))
        this->info_tokens[this->curr_line]
        ->str_v[this->info_tokens[this->curr_line]->curr_token]
        = label;
    } else if (str_contains(NB_CHARS, str[*tmp_pos])) {
        CHECK_FALSE(is_num_remaining(str + *tmp_pos, &nb_len))
        this->info_tokens[this->curr_line]
        ->nbr_v[this->info_tokens[this->curr_line]->curr_token]
        = m_getnbr(str + *tmp_pos);
        *tmp_pos += nb_len;
    } else
        return EXEC_FAIL;

    return EXEC_SUCCESS;
}

int parse_direct_token(tokenizer_t *this)
{
    int tmp_pos = this->data_pos;

    tmp_pos++;
    CHECK_ERR(get_direct_value(
                this,
                this->info_tokens[this->curr_line]->db.buffer,
                &tmp_pos
            )
    );
    this->info_tokens[this->curr_line]
    ->token_type[this->info_tokens[this->curr_line]->curr_token] = DIR_TOKEN;
    this->info_tokens[this->curr_line]
    ->token_length[this->info_tokens[this->curr_line]->curr_token] =
    tmp_pos - this->data_pos;
    return EXEC_SUCCESS;
}