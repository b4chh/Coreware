/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** corewar
*/

#ifndef VM_STRUCT
#define VM_STRUCT

#include "vm/champion.h"
#include "vm/operations.h"
#include "vm/virtual.h"
#include "vm/instruction.h"

#define USAGE "USAGE\n" \
"./corewar [-dump nbr_cycle] [[-n prog_number]" \
" [-a load_address] prog_name] ...\n" \
"DESCRIPTION\n" \
"-dump nbr_cycle dumps the memory after the" \
" nbr_cycle execution (if the round isn’t " \
"already over) with the following format: 32 bytes/line in " \
"hexadecimal (A0BCDEFE1DD3...)\n" \
"-n prog_number sets the next program’s number. By default, " \
"the first free number in the parameter order\n" \
"-a load_address sets the next program’s" \
" loading address. When no address is " \
"specified, optimize the addresses so that the processes are as far\n" \
"away from each other as possible. The addresses are MEM_SIZE modulo.\n"

#define AUTO_ADDR   -1
#define DUMP        0
#define ARG         1
#define AUTO_NBR    -1
#define CHECK_ARG(x)        if (x < 0) return EXEC_FAIL;

#define L_PARAM(x)         ((param_t *) x->element)

typedef struct parameter
{
    int prog_nbr;
    char *path;
    int addr;
} param_t;

typedef struct param_link
{
    char *pattern;
    int (*callback)();
} param_link_t;

param_t *create_param(int addr, int n, char *path);
int destroy_param(param_t *this);

int init_prog_nbr(param_t *this, vm_t *vm, char **av, int *idx);
int init_addr(param_t *this, vm_t *vm, char **av, int *idx);
int init_path(param_t *this, vm_t *vm, char **av, int *idx);

#endif /* !VM */