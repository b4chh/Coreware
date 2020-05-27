/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** destroy_vm.c
*/

#include "utils.h"
#include "vm.h"

int destroy_vm(vm_t *this)
{
    list_destroy(&this->champions, destroy_champion);
    list_destroy(&this->params, destroy_param);
    free(this->memory);
    free(this);
    return EXEC_SUCCESS;
}