/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** and.c
*/

#include "utils.h"
#include "vm.h"

int and_ope_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) =
    args[0].value & REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int and_ope_dir_ind(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value &
    store_int(this->memory, IND(champ, args[1].value));
    return EXEC_SUCCESS;
}

int and_ope_ind_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) =
    store_int(this->memory, IND(champ, args[0].value))
    & REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int and_ope_allreg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) =
    REG(champ, args[0].value) & REG(champ, args[1].value);
    return EXEC_SUCCESS;
}

int and(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_AND, NB_PATTERNS_AND, args))
    (get_correct_pattern(PATTERN_AND, NB_PATTERNS_AND, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}