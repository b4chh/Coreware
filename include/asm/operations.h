/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** operations.h
*/

#ifndef CPE_COREWAR_2019_OPERATIONS_H
#define CPE_COREWAR_2019_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512   /* modulo of the index < */
#define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

#define T_REG           1       /* register */
#define T_DIR           4       /* direct  (ld  #1, r1  put 1 into r1) */
#define T_IND           2       /* indirect always relative */
#define T_INDEX         2
#define T_LAB           8       /* LABEL */

typedef char args_type_t;

typedef enum operation_type {
    LIVE, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD, LLDI,
    LFORK, AFF
} op_e;

typedef struct operations {
    char *name;
    op_e op_type;
    char nb_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int length_token;
} op_t;

typedef struct {
    args_type_t type;
    bool is_index;
    union {
        char reg;
        short ind;
        int dir;
    } args_value;
} args_t;

typedef struct op_index {
    op_e op;
    bool is_index_arg[MAX_ARGS_NUMBER];
} op_index_t;


static const op_index_t INDEXED_OP[] = {
    {ZJMP, {1, 0, 0, 0}},
    {LDI, {1, 1, 0, 0}},
    {STI, {0, 1, 1, 0}},
    {FORK, {1, 0, 0, 0}},
    {LLDI, {1, 1, 0, 0}},
    {LFORK, {1, 0, 0, 0}}
};
static const int NB_INDEXES_OP = sizeof(INDEXED_OP) / sizeof(op_index_t);

bool is_indexes_op(op_e op_type);

// SIZES


static const op_t OPERATIONS[] = {
    {"live", LIVE, 1, {T_DIR}, 1, 10, "alive", 4},
    {"ld", LD, 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 2},
    {"st", ST, 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 2},
    {"add", ADD, 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 3},
    {"sub", SUB, 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 3},
    {"and", AND, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and r1, r2, r3    < r1&r2 -> r3", 3},
    {"or", OR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or r1, r2, r3   r1 | r2 -> r3", 2},
    {"xor", XOR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor r1, r2, r3   r1^r2 -> r3", 3},
    {"zjmp", ZJMP, 1, {T_DIR}, 9, 20, "jump if zero", 4},
    {"ldi", LDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index", 3},
    {"sti", STI, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index", 3},
    {"fork", FORK, 1, {T_DIR}, 12, 800, "fork", 4},
    {"lld", LLD, 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 3},
    {"lldi", LLDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index", 4},
    {"lfork", LFORK, 1, {T_DIR}, 15, 1000, "long fork", 5},
    {"aff", AFF, 1, {T_REG}, 16, 2, "aff", 3}
};
static const int NB_OPERATIONS = sizeof(OPERATIONS) / sizeof(op_t);

int get_operation(char const *name, op_t *op);

#endif