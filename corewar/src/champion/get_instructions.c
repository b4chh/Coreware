/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** byte_code.c
*/

#include "utils.h"
#include "my.h"
#include "vm/champion.h"

int get_instructions(champion_t *this, FILE *fd, int prog_size)
{
    char *tab = malloc(sizeof(char) * prog_size);

    CHECK_NULL(tab);
    m_memset(tab, '\0', prog_size);
    if (lseek(fd->_fileno, 2192, SEEK_SET) < 0)
        return EXEC_FAIL;
    CHECK_FALSE(read(fd->_fileno, tab, prog_size) == prog_size);
    this->bytecode = tab;
    return (EXEC_SUCCESS);
}