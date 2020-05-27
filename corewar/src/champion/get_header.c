/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_header.c
*/

#include "utils.h"
#include "vm/champion.h"

int get_magic_nb(FILE *fd, header_t *head)
{
    read(fd->_fileno, &head->magic, sizeof(int));
    head->magic = reverse_int(head->magic);
    CHECK_FALSE(head->magic == COREWAR_EXEC_MAGIC);
    return (EXEC_SUCCESS);
}

int get_prog_name(FILE *fd, header_t *head)
{
    if (lseek(fd->_fileno, 4, SEEK_SET) < 0)
        return EXEC_FAIL;
    if (read(fd->_fileno, head->prog_name, PROG_NAME_LENGTH) !=
    PROG_NAME_LENGTH)
        return EXEC_FAIL;
    return (EXEC_SUCCESS);
}

int get_prog_size(FILE *fd, header_t *head)
{
    if (lseek(fd->_fileno, 136, SEEK_SET) < 0)
        return EXEC_FAIL;
    if (read(fd->_fileno, &head->prog_size, sizeof(int)) != sizeof(int))
        return EXEC_FAIL;
    head->prog_size = reverse_int(head->prog_size);
    return (EXEC_SUCCESS);
}

int get_comment(FILE *fd, header_t *head)
{
    if (lseek(fd->_fileno, 140, SEEK_SET) < 0)
        return EXEC_FAIL;
    if (read(fd->_fileno, head->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
        return EXEC_FAIL;
    return (0);
}

int get_header(FILE *fd, header_t *head)
{
    CHECK_ERR(get_magic_nb(fd, head));
    CHECK_ERR(get_prog_name(fd, head));
    CHECK_ERR(get_prog_size(fd, head));
    CHECK_ERR(get_comment(fd, head));
    return EXEC_SUCCESS;
}