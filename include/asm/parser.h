/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** parser.h
*/

#ifndef CPE_COREWAR_2019_PARSER_H
#define CPE_COREWAR_2019_PARSER_H

#include "operations.h"
#include "tokenizer.h"

typedef struct directive {
    op_t instruction;
    args_t *args[MAX_ARGS_NUMBER];
    int nb_args;
} directive_t;

typedef struct parser {
    tokenizer_t *tokens;
    int curr_line;
    int index_token;
    int nb_lines;
    directive_t **cmds;
} parser_t;

typedef struct link_token_arg {
    token_type_e type_token;
    int type_arg;
} token_arg_t;

static const token_arg_t TOKEN_ARGS[] = {
    {DIR_TOKEN, T_DIR},
    {IND_TOKEN, T_IND},
    {REG_TOKEN, T_REG}
};
static const int NB_LINK_ARGS = sizeof(TOKEN_ARGS) / sizeof(token_arg_t);

args_type_t get_type_arg_from_token(token_type_e type);
int find_value_label_behind(parser_t *this);
int find_value_label_after(parser_t *this);
int get_arg_size_indexed_op(op_e op, token_type_e token, int pos_arg);
bool is_indexed_arg(op_e op, int pos_arg);
int explore_token_bytes(info_t **tokens, int tmp_line, int *count_bytes);
int check_found_label_before_one(parser_t *this,
int line, int count_bytes, int save);
int check_found_label_before_two(parser_t *this,
int line, int count_bytes, int max);
int check_found_label_after_one(parser_t *this,
int line, int count_bytes);
bool check_found_label_after_two(parser_t *this,
int line, int max);

parser_t *create_parser(tokenizer_t *tokenizer);
int destroy_parser(parser_t *this);

int run_parser(parser_t *this);

bool is_valid_arg(parser_t *this);
int parse_args(parser_t *this);
args_t *create_arg(parser_t *this, args_type_t type, int pos);
int destroy_arg(args_t *this);

directive_t *create_directive(op_t op);
int destroy_directive(directive_t *this);

int reverse_int(int original);
short reverse_short(short original);
int get_prog_size(parser_t *this);

int get_index_start_op(parser_t *this);
int encode_header(parser_t *this, FILE *f);
int get_params_byte(directive_t *cmd, FILE *f);

int encode_bytes(parser_t *this, FILE *f);

#endif
