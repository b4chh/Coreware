/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** encode_header.c
*/

#include "utils.h"
#include "asm.h"

int encode_header(parser_t *this, FILE *f)
{
    int reverse_magic = reverse_int(this->tokens->header_info.magic);
    int reverse_prog_size = reverse_int(this->tokens->header_info.prog_size);
    int pad = 0;

    write(f->_fileno, &reverse_magic, sizeof(reverse_magic));
    write(f->_fileno, this->tokens->header_info.prog_name, PROG_NAME_LENGTH);
    write(f->_fileno, &pad, sizeof(pad));
    write(f->_fileno, &reverse_prog_size, sizeof(reverse_prog_size));
    write(f->_fileno, this->tokens->header_info.comment, COMMENT_LENGTH);
    write(f->_fileno, &pad, sizeof(pad));
    return EXEC_SUCCESS;
}