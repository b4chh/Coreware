/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** sti_2.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int sti_reg_reg_dir(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ, (REG(champ, args[1].value) + args[2].value))
            % IDX_MOD,
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    return EXEC_SUCCESS;
}

int sti_reg_ind_dir(vm_t *this, champion_t *champ, args_t *args)
{
    write_memory(
            this->memory,
            IND(champ,
            ((int) store_short(this->memory, IND(champ, args[1].value))
            + args[2].value) % IDX_MOD),
            REG_SIZE,
            reverse_int(REG(champ, args[0].value))
    );
    show_mem(this->memory, 64);
    return EXEC_SUCCESS;
}