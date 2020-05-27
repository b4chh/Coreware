/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** success_label_checker.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int check_found_label_before_one(parser_t *this,
int line, int count_bytes, int save)
{
    if (this->tokens->info_tokens[line]->token_type[0] == LBL_OPT_TOKEN
        && m_strcmp(this->tokens->info_tokens[line]
        ->str_v[0], this->tokens->info_tokens[this->curr_line]
        ->str_v[this->index_token]) == 0) {
        this->tokens->info_tokens[this->curr_line]->nbr_v[this->index_token]
        = (count_bytes + save) * -1;
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

int check_found_label_before_two(parser_t *this,
int line, int count_bytes, int max)
{
    if (this->tokens->info_tokens[line]->token_type[max] == LBL_OPT_TOKEN
        && m_strcmp(this->tokens->info_tokens[line]
        ->str_v[max], this->tokens->info_tokens[this->curr_line]
        ->str_v[this->index_token]) == 0) {
        this->tokens->info_tokens[this->curr_line]->nbr_v[this->index_token]
        = count_bytes * -1;
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

int check_found_label_after_one(parser_t *this,
int line, int count_bytes)
{
    if (this->tokens->info_tokens[line]->token_type[0] == LBL_OPT_TOKEN
        && m_strcmp(this->tokens->info_tokens[line]
        ->str_v[0], this->tokens->info_tokens[this->curr_line]
        ->str_v[this->index_token]) == 0) {
        this->tokens->info_tokens[this->curr_line]->nbr_v[this->index_token]
        = count_bytes;
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

bool check_found_label_after_two(parser_t *this,
int line, int max)
{
    if (this->tokens->info_tokens[line]->token_type[max] == LBL_OPT_TOKEN
    && m_strcmp(this->tokens->info_tokens[line]
    ->str_v[max], this->tokens->info_tokens[this->curr_line]
    ->str_v[this->index_token]) == 0)
        return true;
    return false;
}