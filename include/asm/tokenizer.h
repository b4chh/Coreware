/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** tokenizer.h
*/

#ifndef CPE_COREWAR_2019_TOKENIZER_H
#define CPE_COREWAR_2019_TOKENIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','
#define STRING_CHAR             '"'

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
#define OP_CHARS                "lsaoxzf"
#define NB_CHARS                "0123456789"

#define NAME_CMD                ".name"
#define COMMENT_CMD             ".comment"

#define REG_NUMBER              16

#define DATA_BUFFER(x) (data_buffer_t) {x, m_strlen(x)}

typedef enum token_type {
    LBL_OPT_TOKEN,
    MNE_TOKEN,
    IND_TOKEN,
    REG_TOKEN,
    DIR_TOKEN,
    NULL_TOKEN
} token_type_e;

typedef char reg_t;

typedef struct data_buffer {
    char *buffer;
    int len;
} data_buffer_t;

// Header

#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048
#define COREWAR_EXEC_MAGIC  0xea83f3

typedef struct header {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct info {
    data_buffer_t db;
    token_type_e *token_type;
    int *token_length;
    int nb_tokens;
    int curr_token;
    char **str_v;
    int *nbr_v;
    reg_t *reg_v;
} info_t;

typedef struct tokenizer {
    int nb_lines;
    int curr_line;
    int data_pos;
    header_t header_info;
    info_t **info_tokens;
} tokenizer_t;

typedef struct link_token {
    char const *str;
    int (*callback)();
} link_token_t;

int parse_register_token(tokenizer_t *this);
int parse_mnemonic_token(tokenizer_t *this);
int parse_direct_token(tokenizer_t *this);
int parse_indirect_value(tokenizer_t *this);

static const link_token_t TOKEN_OPS[] = {
    {"r", parse_register_token}, //parse_register_value
    {OP_CHARS, parse_mnemonic_token}, //parse_mne;
    {NB_CHARS, parse_indirect_value}, // parse_indirect_value
    {"%", parse_direct_token}, // parse direct value
};
static const int NB_TOKENS = sizeof(TOKEN_OPS) / sizeof(link_token_t);


// TOKENIZER OBJECT FUNCTIONS


tokenizer_t *create_tokenizer(char **content, int nb_lines);
int destroy_tokenizer(tokenizer_t *this);

int run_lexer(tokenizer_t *this);

bool check_label_dec(tokenizer_t *this);
void skip_white_spaces(tokenizer_t *this);
bool is_space(char c);
int eat_comma(tokenizer_t *this);
int eat_space(tokenizer_t *this);
int check_end(tokenizer_t *this);

bool parse_label_dec(tokenizer_t *this);
int parse_instruction_token(tokenizer_t *this);

int get_header_info(tokenizer_t *this);
char *get_label_dec_value(char const *str, int start_pos, int length);

bool is_num_remaining(char const *str, int *length);

// INFO TOKENS OBJECT FUNCTIONS

info_t *create_info(char *line);
int destroy_info(info_t *this);

char *trim_start_spaces(char *buffer);
#endif