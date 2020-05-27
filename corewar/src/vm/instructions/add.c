/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** add.c
*/

#include "utils.h"
#include "vm.h"

int add_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) =
    REG(champ, args[0].value) + REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int add(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_ADD, NB_PATTERNS_ADD, args))
    (get_correct_pattern(PATTERN_ADD, NB_PATTERNS_ADD, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}