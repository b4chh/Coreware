/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** m_strncpy.c
*/

#include "my.h"

char *m_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != 0 && i < n; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}