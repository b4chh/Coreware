/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** setup_memory.c
*/

#include "utils.h"
#include "my.h"
#include "vm.h"

int setup_memory(vm_t *this)
{
    this->memory = malloc(sizeof(__u_char) * MEM_SIZE);

    CHECK_NULL(this->memory)
    m_memset(this->memory, 0, MEM_SIZE);
    return EXEC_SUCCESS;
}