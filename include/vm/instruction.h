/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instruction.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_H
#define CPE_COREWAR_2019_INSTRUCTION_H

#include "champion.h"
#include "operations.h"

typedef struct pattern_op
{
    args_type_t types[MAX_ARGS_NUMBER];
    int (*callback)(vm_t *this, champion_t *, args_t *args);
} pattern_op_t;

int (*get_correct_pattern(pattern_op_t const *patterns,
int nb_patterns, args_t *args))( );

int sti_reg_reg_reg(vm_t *this, champion_t *champ, args_t *args);
int sti_reg_ind_reg(vm_t *this, champion_t *champ, args_t *args);
int sti_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int sti_reg_reg_dir(vm_t *this, champion_t *champ, args_t *args);
int sti_reg_ind_dir(vm_t *this, champion_t *champ, args_t *args);
int sti_reg_dir_dir(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_STI[] = {
        {{T_REG, T_REG, T_REG}, sti_reg_reg_reg},
        {{T_REG, T_IND, T_REG}, sti_reg_ind_reg},
        {{T_REG, T_DIR, T_REG}, sti_reg_dir_reg},

        {{T_REG, T_REG, T_DIR}, sti_reg_reg_dir},
        {{T_REG, T_IND, T_DIR}, sti_reg_ind_dir},
        {{T_REG, T_DIR, T_DIR}, sti_reg_dir_dir}
};
static const int NB_PATTERNS_STI = sizeof(PATTERN_STI) / sizeof(pattern_op_t);

// AND PATTERNS AND.C

int and_ope_allreg(vm_t *this, champion_t *champ, args_t *args);
int and_ope_reg_ind(vm_t *this, champion_t *champ, args_t *args);
int and_ope_reg_dir(vm_t *this, champion_t *champ, args_t *args);
int and_ope_two_dir(vm_t *this, champion_t *champ, args_t *args);
int and_ope_two_ind(vm_t *this, champion_t *champ, args_t *args);
int and_ope_ind_dir(vm_t *this, champion_t *champ, args_t *args);
int and_ope_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int and_ope_dir_ind(vm_t *this, champion_t *champ, args_t *args);
int and_ope_ind_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_AND[] = {
        {{T_REG, T_REG, T_REG}, and_ope_allreg},
        {{T_REG, T_IND, T_REG}, and_ope_reg_ind},
        {{T_REG, T_DIR, T_REG}, and_ope_reg_dir},

        {{T_DIR, T_DIR, T_REG}, and_ope_two_dir},
        {{T_IND, T_IND, T_REG}, and_ope_two_ind},
        {{T_IND, T_DIR, T_REG}, and_ope_ind_dir},

        {{T_DIR, T_REG, T_REG}, and_ope_dir_reg},
        {{T_DIR, T_IND, T_REG}, and_ope_dir_ind},
        {{T_IND, T_REG, T_REG}, and_ope_ind_reg}
};
static const int NB_PATTERNS_AND = sizeof(PATTERN_AND) / sizeof(pattern_op_t);


// OR PATTERNS OR.C

int or_ope_allreg(vm_t *this, champion_t *champ, args_t *args);
int or_ope_reg_ind(vm_t *this, champion_t *champ, args_t *args);
int or_ope_reg_dir(vm_t *this, champion_t *champ, args_t *args);
int or_ope_two_dir(vm_t *this, champion_t *champ, args_t *args);
int or_ope_two_ind(vm_t *this, champion_t *champ, args_t *args);
int or_ope_ind_dir(vm_t *this, champion_t *champ, args_t *args);
int or_ope_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int or_ope_dir_ind(vm_t *this, champion_t *champ, args_t *args);
int or_ope_ind_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_OR[] = {
        {{T_REG, T_REG, T_REG}, or_ope_allreg},
        {{T_REG, T_IND, T_REG}, or_ope_reg_ind},
        {{T_REG, T_DIR, T_REG}, or_ope_reg_dir},

        {{T_DIR, T_DIR, T_REG}, or_ope_two_dir},
        {{T_IND, T_IND, T_REG}, or_ope_two_ind},
        {{T_IND, T_DIR, T_REG}, or_ope_ind_dir},

        {{T_DIR, T_REG, T_REG}, or_ope_dir_reg},
        {{T_DIR, T_IND, T_REG}, or_ope_dir_ind},
        {{T_IND, T_REG, T_REG}, or_ope_ind_reg}
};
static const int NB_PATTERNS_OR = sizeof(PATTERN_OR) / sizeof(pattern_op_t);

// XOR PATTERNS XOR.C

int xor_ope_allreg(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_reg_ind(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_reg_dir(vm_t *this, champion_t *champ, args_t *args);

int xor_ope_two_dir(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_two_ind(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_ind_dir(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_dir_ind(vm_t *this, champion_t *champ, args_t *args);
int xor_ope_ind_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_XOR[] = {
        {{T_REG, T_REG, T_REG}, xor_ope_allreg},
        {{T_REG, T_IND, T_REG}, xor_ope_reg_ind},
        {{T_REG, T_DIR, T_REG}, xor_ope_reg_dir},

        {{T_DIR, T_DIR, T_REG}, xor_ope_two_dir},
        {{T_IND, T_IND, T_REG}, xor_ope_two_ind},
        {{T_IND, T_DIR, T_REG}, xor_ope_ind_dir},

        {{T_DIR, T_REG, T_REG}, xor_ope_dir_reg},
        {{T_DIR, T_IND, T_REG}, xor_ope_dir_ind},
        {{T_IND, T_REG, T_REG}, xor_ope_ind_reg}
};
static const int NB_PATTERNS_XOR = sizeof(PATTERN_XOR) / sizeof(pattern_op_t);

// LDI PATTERNS LDI.C

int ldi_ind_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int ldi_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int ldi_dir_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int ldi_ind_reg_reg(vm_t *this, champion_t *champ, args_t *args);
int ldi_dir_reg_reg(vm_t *this, champion_t *champ, args_t *args);
int ldi_reg_reg_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_LDI[] = {
        {{T_REG, T_DIR, T_REG}, ldi_reg_dir_reg},
        {{T_DIR, T_DIR, T_REG}, ldi_dir_dir_reg},
        {{T_IND, T_DIR, T_REG}, ldi_ind_dir_reg},

        {{T_IND, T_REG, T_REG}, ldi_ind_reg_reg},
        {{T_DIR, T_REG, T_REG}, ldi_dir_reg_reg},
        {{T_REG, T_REG, T_REG}, ldi_reg_reg_reg}
};
static const int NB_PATTERNS_LDI = sizeof(PATTERN_LDI) / sizeof(pattern_op_t);


// LD PATTERNS LD.C

int ld_dir(vm_t *this, champion_t *champ, args_t *args);
int ld_ind(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_LD[] = {
    {{T_DIR, T_REG}, ld_dir},
    {{T_IND, T_REG}, ld_ind}
};
static const int NB_PATTERNS_LD = sizeof(PATTERN_LD) / sizeof(pattern_op_t);

// ST PATTERNS ST.C

int st_reg(vm_t *this, champion_t *champ, args_t *args);
int st_ind(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_ST[] = {
    {{T_REG, T_REG}, st_reg},
    {{T_REG, T_IND}, st_ind}
};
static const int NB_PATTERNS_ST = sizeof(PATTERN_ST) / sizeof(pattern_op_t);

// ADD PATTERNS ADD.C

int add_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_ADD[] = {
    {{T_REG, T_REG, T_REG}, add_reg}
};
static const int NB_PATTERNS_ADD = sizeof(PATTERN_ADD) / sizeof(pattern_op_t);

// SUB PATTERNS SUB.C

int sub_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_SUB[] = {
    {{T_REG, T_REG, T_REG}, sub_reg}
};
static const int NB_PATTERNS_SUB = sizeof(PATTERN_SUB) / sizeof(pattern_op_t);


// LLD PATTERNS LLD.C

int lld_dir(vm_t *this, champion_t *champ, args_t *args);
int lld_ind(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_LLD[] = {
        {{T_DIR, T_REG}, lld_dir},
        {{T_IND, T_REG}, lld_ind}
};
static const int NB_PATTERNS_LLD = sizeof(PATTERN_LLD) / sizeof(pattern_op_t);

// LLDI PATTERNS LLDI.C

int lldi_ind_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int lldi_reg_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int lldi_dir_dir_reg(vm_t *this, champion_t *champ, args_t *args);
int lldi_ind_reg_reg(vm_t *this, champion_t *champ, args_t *args);
int lldi_dir_reg_reg(vm_t *this, champion_t *champ, args_t *args);
int lldi_reg_reg_reg(vm_t *this, champion_t *champ, args_t *args);

static const pattern_op_t PATTERN_LLDI[] = {
        {{T_REG, T_DIR, T_REG}, lldi_reg_dir_reg},
        {{T_DIR, T_DIR, T_REG}, lldi_dir_dir_reg},
        {{T_IND, T_DIR, T_REG}, lldi_ind_dir_reg},

        {{T_IND, T_REG, T_REG}, lldi_ind_reg_reg},
        {{T_DIR, T_REG, T_REG}, lldi_dir_reg_reg},
        {{T_REG, T_REG, T_REG}, lldi_reg_reg_reg}
};
static const int NB_PATTERNS_LLDI = sizeof(PATTERN_LLDI) / sizeof(pattern_op_t);

#endif