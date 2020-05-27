/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** aff.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int aff(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    m_putchar(REG(champ, args[0].value) % 256);
    return EXEC_SUCCESS;
}