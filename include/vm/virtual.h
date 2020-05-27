/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** virtual.h
*/

#ifndef CPE_COREWAR_2019_VIRTUAL_H
#define CPE_COREWAR_2019_VIRTUAL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40

#define CIRCULAR(x)     (x % MEM_SIZE)
#define TO_BITS(x)      (x * 8)

typedef char args_type_t;

typedef struct argument {
    op_t op;
    args_type_t type;
    int value;
} args_t;

typedef struct virtual_machine {
    int nb_champions;
    list_t *champions;
    list_t *params;
    __u_char *memory;
    int total_cycles;
    int counter_live;
    champion_t *last_champ_live;
    bool is_dump;
    int cycle_to_dump;
} vm_t;

vm_t *create_vm(void);
int destroy_vm(vm_t *this);

int load_champions(vm_t *this);
int setup_memory(vm_t *this);
int run_corewar(vm_t *this);
/*display_vm_message*/
void give_msg_live(champion_t *this);
void give_msg_win(champion_t *this);

int get_champ_size(list_t *champ);
int set_memory(vm_t *this);
int write_memory(__u_char *mem, int idx, int size, int value);

// Instruction execution

int exec_instruction(vm_t *this, champion_t *champ, op_t op);
int get_size_instruction(vm_t *this, int curr_idx);
int launch_instruction(vm_t *this, champion_t *champ);
int get_args_type_from_byte
(unsigned char params_byte, op_t, args_type_t *params);
int get_size_from_args(op_t op, args_type_t *type);
int find_pc(vm_t *this, champion_t *champ);
int get_args(vm_t *this, args_t *args, int idx);

int load_params(vm_t *this, int ac, char **av);
void list_push_after_tag(list_t **list, void *element, char const *tag,
char const *after);
int show_mem(__u_char const *mem, int size);
#endif