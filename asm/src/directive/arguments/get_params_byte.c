/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_params_byte.c
*/

#include "utils.h"
#include "asm.h"

int get_params_byte(directive_t *cmd, FILE *f)
{
    int i = 0;
    char byte = 0;

    for (i = 0; i < cmd->nb_args; i++) {
        switch (cmd->args[i]->type) {
            case T_REG: byte = byte << 2 | (T_REG & 0x03);
                break;
            case T_DIR: byte = byte << 2 | (T_IND & 0x03);
                break;
            case T_IND: byte =  byte << 2 | ((T_IND | T_REG) & 0x03);
                break;
            default: break;
        }
    }
    for (; i < MAX_ARGS_NUMBER; i++, byte = byte << 2);
    write(f->_fileno, &byte, sizeof(char));
    return EXEC_SUCCESS;
}