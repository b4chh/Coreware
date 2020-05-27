/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** encoding.c
*/

#include "utils.h"
#include "asm.h"

static void choose_write_format(directive_t *cmd, FILE *f, int i)
{
    int dir = 0;

    switch (cmd->args[i]->type) {
        case T_DIR:
            dir = reverse_int(cmd->args[i]->args_value.dir);
            write(f->_fileno, &dir, sizeof(dir));
            break;
        case T_REG:
            write(f->_fileno, &cmd->args[i]->args_value.reg, sizeof(char));
            break;
        default: break;
    }
}

int write_bytes_args(directive_t *cmd, FILE *f)
{
    short ind = 0;

    for (int i = 0; i < cmd->nb_args; i++) {
        if (cmd->args[i]->is_index || cmd->args[i]->type == T_IND) {
            ind = reverse_short(cmd->args[i]->args_value.ind);
            write(f->_fileno, &ind, sizeof(ind));
            continue;
        }
        choose_write_format(cmd, f, i);
    }
    return EXEC_SUCCESS;
}

int encode_bytes(parser_t *this, FILE *f)
{
    int i = 0;
    op_t op;

    this->curr_line = 0;
    for (i = 0; i < this->nb_lines; i++) {
        if (!this->cmds[i])
            continue;
        op = this->cmds[i]->instruction;
        write(f->_fileno, &op.code, sizeof(char));
        if (op.op_type != LIVE && op.op_type != ZJMP && op.op_type != FORK
        && op.op_type != LFORK)
            get_params_byte(this->cmds[i], f);
        write_bytes_args(this->cmds[i], f);
    }
    return EXEC_SUCCESS;
}