/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** comments.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

bool contains_comment(char const *buffer, int *index_start)
{
    int i = 0;

    for (i = 0; buffer[i]; i++) {
        if (buffer[i] == COMMENT_CHAR) {
            *index_start = i;
            return true;
        }
    }
    *index_start = -1;
    return false;
}

void clear_comment(char *buffer, int index_start)
{
    int i = 0;

    for (i = index_start; buffer[i]; i++)
        buffer[i] = '\0';
}

bool empty_string(char *buffer)
{
    int index_comment = 0;

    if (contains_comment(buffer, &index_comment))
        clear_comment(buffer, index_comment);
    return m_strlen(buffer) == 0;
}