/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** buffer_operations.c
*/

#include "utils.h"
#include "asm.h"
#include "my.h"

char *clear_buffer(char *buffer, int length)
{
    if (buffer[length - 1] == '\n')
        buffer[length - 1] = '\0';
    return buffer;
}

void reset_buffer(char **buffer, size_t *n)
{
    *n = 0;
    free(*buffer);
}

bool str_contains(char const *str, char c)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == c)
            return true;
    return false;
}

bool is_valid_cmd(char const *str)
{
    if (m_strncmp(NAME_CMD, str, m_strlen(NAME_CMD)) == 0)
        return true;
    if (m_strncmp(COMMENT_CMD, str, m_strlen(COMMENT_CMD)) == 0)
        return true;
    return false;
}