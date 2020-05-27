/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ld.c
*/

#include "utils.h"
#include "vm.h"

int ld_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[1].value) = args[0].value;
    return EXEC_SUCCESS;
}

int ld_ind(vm_t *this, champion_t *champ, args_t *args)
{

    REG(champ, args[1].value) = store_int(
            this->memory,
            IND(champ, args[0].value) % IDX_MOD
    );
    return EXEC_SUCCESS;
}

int ld(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_LD, NB_PATTERNS_LD, args))
    (get_correct_pattern(PATTERN_LD, NB_PATTERNS_LD, args))
    (this, champ, args);
    champ->carry = true;
    return EXEC_SUCCESS;
}