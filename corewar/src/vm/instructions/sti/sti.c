/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** sti.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int sti_reg_dir_dir(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, (args[1].value + args[2].value)) % IDX_MOD,
            REG_SIZE,
            reverse_int( REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int sti_reg_reg_reg(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, (REG(champ, args[1].value)
            + REG(champ, args[2].value))) % IDX_MOD,
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int sti_reg_ind_reg(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, ((int) store_short(this->memory,
            IND(champ, args[1].value))
            + REG(champ, args[2].value))) % IDX_MOD,
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int sti_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, (args[1].value + REG(champ, args[2].value)))
            % IDX_MOD,
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int sti(vm_t *this, champion_t *champ, args_t *args)
{
    CHECK_NULL(get_correct_pattern(PATTERN_STI, NB_PATTERNS_STI, args))
    (get_correct_pattern(PATTERN_STI, NB_PATTERNS_STI, args))
    (this, champ, args);
    return EXEC_SUCCESS;
}
