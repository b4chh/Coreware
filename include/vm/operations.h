/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** operations.h
*/

#ifndef CPE_COREWAR_2019_OPERATIONS_H
#define CPE_COREWAR_2019_OPERATIONS_H

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512

# define T_REG           1
# define T_DIR           2
# define T_IND           4

#define MAX_ARGS_NUMBER         4

#define IND(c, v)       c->reg[PC_IDX] + v
#define REG(c, v)       c->reg[v]

typedef enum operation_type {
    LIVE, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD, LLDI,
    LFORK, AFF
} op_e;

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
op_index_t get_indexes_op(op_e op_type);
bool is_indexed_arg(op_e op, int pos_arg);

typedef char args_type_t;
typedef struct virtual_machine vm_t;
typedef struct argument args_t;

struct  op_s
{
    char            *mnemonique;
    op_e            op_type;
    char            nbr_args;
    args_type_t     type[MAX_ARGS_NUMBER];
    char            code;
    int             nbr_cycles;
    char            *comment;
    int             (*callback)(vm_t *, champion_t *, args_t *args);
};
typedef struct op_s op_t;

int add(vm_t *this, champion_t *champ, args_t *args);
int aff(vm_t *this, champion_t *champ, args_t *args);
int and(vm_t *this, champion_t *champ, args_t *args);
int fork_op(vm_t *this, champion_t *champ, args_t *args);
int ld(vm_t *this, champion_t *champ, args_t *args);
int ldi(vm_t *this, champion_t *champ, args_t *args);
int lfork(vm_t *this, champion_t *champ, args_t *args);
int live(vm_t *this, champion_t *champ, args_t *args);
int lld(vm_t *this, champion_t *champ, args_t *args);
int lldi(vm_t *this, champion_t *champ, args_t *args);
int or(vm_t *this, champion_t *champ, args_t *args);
int st(vm_t *this, champion_t *champ, args_t *args);
int sti(vm_t *this, champion_t *champ, args_t *args);
int sub(vm_t *this, champion_t *champ, args_t *args);
int xor(vm_t *this, champion_t *champ, args_t *args);
int zjmp(vm_t *this, champion_t *champ, args_t *args);

static const op_t OPERATIONS[] = {
    {"live", LIVE, 1, {T_DIR}, 1, 10, "alive", live},
    {"ld", LD, 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", ld},
    {"st", ST, 2, {T_REG, T_IND | T_REG}, 3, 5, "store", st},
    {"add", ADD, 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", add},
    {"sub", SUB, 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", sub},
    {"and", AND, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and r1, r2, r3    < r1&r2 -> r3", and},
    {"or", OR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or r1, r2, r3   r1 | r2 -> r3", or},
    {"xor", XOR, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor r1, r2, r3   r1^r2 -> r3", xor},
    {"zjmp", ZJMP, 1, {T_DIR}, 9, 20, "jump if zero", zjmp},
    {"ldi", LDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index", ldi},
    {"sti", STI, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index", sti},
    {"fork", FORK, 1, {T_DIR}, 12, 800, "fork", fork_op},
    {"lld", LLD, 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", lld},
    {"lldi", LLDI, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index", lldi},
    {"lfork", LFORK, 1, {T_DIR}, 15, 1000, "long fork", lfork},
    {"aff", AFF, 1, {T_REG}, 16, 2, "aff", aff}
};
static const int NB_OPERATIONS = sizeof(OPERATIONS) / sizeof(op_t);

int get_operation(unsigned char code, op_t *op);
bool has_param_byte(op_t op);

#endif