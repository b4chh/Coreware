/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_tokenizer.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

tokenizer_t *create_tokenizer(char **content, int nb_lines)
{
    tokenizer_t *this = malloc(sizeof(tokenizer_t));

    CHECK_MALLOC(this);
    this->nb_lines = nb_lines;
    this->data_pos = 0;
    this->curr_line = 0;
    this->info_tokens = malloc(sizeof(info_t *) * nb_lines);
    for (int i = 0; i < nb_lines; i++)
        this->info_tokens[i] = create_info(content[i]);
    CHECK_MALLOC(this->info_tokens);
    return this;
}