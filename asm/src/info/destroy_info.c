/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_info.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

int destroy_info(info_t *this)
{
    int i = 0;

    for (i = 0; i < this->db.len; i++)
        free(this->str_v[i]);
    free(this->token_length);
    free(this->token_type);
    free(this->str_v);
    free(this->reg_v);
    free(this->nbr_v);
    free(this);
    return EXEC_SUCCESS;
}