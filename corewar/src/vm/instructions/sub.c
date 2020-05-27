/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** sub.c
*/

#include "utils.h"
#include "vm.h"

int sub_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) =
    REG(champ, args[0].value) - REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int sub(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_SUB, NB_PATTERNS_SUB, args))
    (get_correct_pattern(PATTERN_SUB, NB_PATTERNS_SUB, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}