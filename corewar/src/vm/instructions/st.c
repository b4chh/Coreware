/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** st.c
*/

#include "utils.h"
#include "vm.h"

int st_reg(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[1].value) = REG(champ, args[0].value);
    return EXEC_SUCCESS;
}

int st_ind(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, args[1].value) % IDX_MOD,
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int st(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_ST, NB_PATTERNS_ST, args))
    (get_correct_pattern(PATTERN_ST, NB_PATTERNS_ST, args))
    (this, champ, args);
    return EXEC_SUCCESS;
}