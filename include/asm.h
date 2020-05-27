/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** asm.h
*/

#ifndef CPE_COREWAR_2019_ASM_H
#define CPE_COREWAR_2019_ASM_H

#include "asm/tokenizer.h"
#include "asm/operations.h"
#include "asm/parser.h"

char *clear_buffer(char *buffer, int length);
void reset_buffer(char **buffer, size_t *n);
bool contains_comment(char const *buffer, int *index_start);
void clear_comment(char *buffer, int index_start);
bool empty_string(char *buffer);
bool str_contains(char const *str, char c);
bool is_valid_cmd(char const *str);
int get_length_file(FILE *file);
char **store_file(FILE *file, int length_file);
int compile(tokenizer_t *tokenizer, char *location);

#endif