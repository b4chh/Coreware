/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** champion.h
*/

#ifndef CPE_COREWAR_2019_CHAMPION_H
#define CPE_COREWAR_2019_CHAMPION_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define REG_NUMBER              16

#define IND_SIZE                2
#define DIR_SIZE                4
#define REG_SIZE                DIR_SIZE

#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048
#define COREWAR_EXEC_MAGIC      0xea83f3

#define PC_IDX                  0

#define L_CHAMP(x)  ((champion_t *) (x->element))

struct header_s
{
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
};
typedef struct header_s header_t;

typedef struct champion {
    int reg[REG_NUMBER + 1];
    int id_champ;
    int pos;
    int wait_for_op;
    bool say_live;
    bool finished;
    bool carry;
    header_t header;
    char *bytecode;
} champion_t;

champion_t *create_champion(int prog_nbr, FILE *bin);
champion_t *duplicate_champion(champion_t *parent);
int destroy_champion(champion_t *this);
int get_instructions(champion_t *this, FILE *fd, int prog_size);
int set_prog_nbr(champion_t *this, int nbr);

int get_magic_nb(FILE *fd, header_t *head);
int get_prog_name(FILE *fd, header_t *head);
int get_prog_size(FILE *fd, header_t *head);
int get_comment(FILE *fd, header_t *head);
int get_header(FILE *fd, header_t *head);
int get_instructions(champion_t *this, FILE *fd, int prog_size);

int reverse_int(int original);
short reverse_short(short original);

int store_int(__u_char *mem, int idx);
short store_short(__u_char *mem, int idx);

#endif