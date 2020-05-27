/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lld.c
*/

#include "utils.h"
#include "vm.h"

int lld_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[1].value) = args[0].value;
    return EXEC_SUCCESS;
}

int lld_ind(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[1].value) = store_int(
            this->memory,
            IND(champ, args[0].value)
    );
    return EXEC_SUCCESS;
}

int lld(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_LLD, NB_PATTERNS_LLD, args))
    (get_correct_pattern(PATTERN_LLD, NB_PATTERNS_LLD, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}