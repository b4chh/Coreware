/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** find_pc.c
*/

#include "utils.h"
#include "vm.h"

int find_pc(vm_t *this, champion_t *champ)
{
    int size = get_size_instruction(this, champ->reg[PC_IDX]);

    if (CIRCULAR(champ->reg[PC_IDX] + size) == champ->header.prog_size)
        champ->finished = true;
    else
        champ->reg[PC_IDX] = CIRCULAR(champ->reg[PC_IDX] + size);
    return EXEC_SUCCESS;
}