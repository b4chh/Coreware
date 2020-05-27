/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_tokenizer.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

int destroy_tokenizer(tokenizer_t *this)
{
    for (int i = 0; i < this->nb_lines; i++)
        destroy_info(this->info_tokens[i]);
    free(this->info_tokens);
    free(this);
    return EXEC_SUCCESS;
}