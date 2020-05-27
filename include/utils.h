/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** utils.h
*/

#ifndef CPE_COREWAR_2019_UTILS_H
#define CPE_COREWAR_2019_UTILS_H

#include <stdlib.h>

#define EXEC_FAIL       84
#define EXEC_SUCCESS    0

#define CHECK_FALSE(x) if (!(x)) return EXEC_FAIL;
#define CHECK_FALSE_VOID(x) if (!(x)) return;
#define CHECK_TRUE(x) if ((x)) return EXEC_SUCCESS;
#define CHECK_NULL(x) if (!(x)) return EXEC_FAIL;
#define CHECK_MALLOC(x) if (!(x)) return NULL;
#define CHECK_ERR_PTR(x) if ((x) == EXEC_FAIL) return NULL;
#define CHECK_ERR(x) if ((x) == EXEC_FAIL) return EXEC_FAIL;
#define CHECK_SUCCESS(x) if ((x) == EXEC_SUCCESS) return EXEC_SUCCESS;

#define BYTE_PER_LINE   32

#define L_TAG(x, y) list_get_from_tag(x, y)

int m_pow(int n, int p);

#endif