/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_operation.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int get_operation(char const *name, op_t *op)
{
    op_t find_operation = {0, 0, 0, {0, 0, 0}, 0, 0, 0, 0};
    int i = 0;

    for (i = 0; i < NB_OPERATIONS; i++) {
        if (m_strcmp(OPERATIONS[i].name, name) == 0) {
            *op = OPERATIONS[i];
            return EXEC_SUCCESS;
        }
    }
    *op = find_operation;
    return EXEC_FAIL;
}