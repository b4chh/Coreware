/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_champion.c
*/

#include "utils.h"
#include "vm/champion.h"

int destroy_champion(champion_t *this)
{
    if (this->bytecode)
        free(this->bytecode);
    free(this);
    return EXEC_SUCCESS;
}