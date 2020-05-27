/*
** EPITECH PROJECT, 2020
** CoreWare
** File description:
** other_function_for_the_file_and
*/

#include "utils.h"
#include "vm.h"

int and_ope_reg_ind(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = REG(champ, args[0].value) &
    store_int(this->memory, IND(champ, args[1].value));
    return EXEC_SUCCESS;
}

int and_ope_reg_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = REG(champ, args[0].value) & args[1].value;
    return EXEC_SUCCESS;
}

int and_ope_two_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value & args[1].value;
    return EXEC_SUCCESS;
}

int and_ope_two_ind(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) =
    store_int(this->memory, IND(champ, args[0].value)) &
    store_int(this->memory, IND(champ, args[1].value));
    return EXEC_SUCCESS;
}

int and_ope_ind_dir(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) =
    store_int(this->memory, IND(champ, args[0].value))
    & args[1].value;
    return EXEC_SUCCESS;
}