/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** set_prog_nbr.c
*/

#include "vm.h"

int set_prog_nbr(champion_t *this, int nbr)
{
    this->id_champ = nbr;
    REG(this, 1) = nbr;
    return COREWAR_EXEC_MAGIC;
}