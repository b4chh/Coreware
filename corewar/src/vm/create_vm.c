/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_vm.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

vm_t *create_vm(void)
{
    vm_t *this = malloc(sizeof(vm_t));
    CHECK_MALLOC(this)
    this->nb_champions = 0;
    this->champions = NULL;
    this->params = NULL;
    this->memory = NULL;
    this->last_champ_live = NULL;
    this->total_cycles = CYCLE_TO_DIE;
    this->counter_live = 0;
    this->cycle_to_dump = 0;
    this->is_dump = false;
    CHECK_ERR_PTR(setup_memory(this))
    return this;
}