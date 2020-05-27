/*
** EPITECH PROJECT, 2020
** CoreWare
** File description:
** Function_of_xor
*/

#include "utils.h"
#include "vm.h"

int xor_ope_reg_ind(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) = REG(champ, args[0].value) ^
    store_int(this->memory, IND(champ, args[1].value));
    return EXIT_SUCCESS;
}

int xor_ope_reg_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = REG(champ, args[0].value) ^ args[1].value;
    return EXIT_SUCCESS;
}

int xor_ope_two_dir(vm_t *this, champion_t *champ, args_t *args)
{
    (void) this;
    REG(champ, args[2].value) = args[0].value ^ args[1].value;
    return EXIT_SUCCESS;
}

int xor_ope_two_ind(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) =
    store_int(this->memory, IND(champ, args[0].value)) ^
    store_int(this->memory, IND(champ, args[1].value));
    return EXIT_SUCCESS;
}

int xor_ope_ind_dir(vm_t *this, champion_t *champ, args_t *args)
{
    REG(champ, args[2].value) =
    store_int(this->memory, IND(champ, args[0].value))
    ^ args[1].value;
    return EXIT_SUCCESS;
}