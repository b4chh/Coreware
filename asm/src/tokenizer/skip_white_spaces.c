/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** skip_white_spaces.c
*/

#include "utils.h"
#include "asm/tokenizer.h"

void skip_white_spaces(tokenizer_t *this)
{
    bool is_white_space = true;

    while (is_white_space) {
        switch (this->info_tokens[this->curr_line]
                ->db.buffer[this->data_pos]) {
            case ' ':
            case '\r':
            case '\t':
            case '\n':
                this->data_pos++;
                break;
            default:
                is_white_space = false;
        }
    }
}