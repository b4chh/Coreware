/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** info.c
*/

#include "utils.h"
#include "asm/tokenizer.h"
#include "my.h"

static void init_arrays(info_t *this)
{
    int i = 0;

    for (i = 0; i < this->db.len; i++) {
        this->token_length[i] = 0;
        this->token_type[i] = NULL_TOKEN;
        this->token_type[i] = NULL_TOKEN;
        this->reg_v[i] = 0;
        this->str_v[i] = NULL;
        this->nbr_v[i] = -1;
    }
}

info_t *create_info(char *line)
{
    info_t *this = malloc(sizeof(info_t));

    CHECK_MALLOC(this);
    this->db = DATA_BUFFER(line);
    this->db.buffer = trim_start_spaces(this->db.buffer);
    this->curr_token = 0;
    this->nb_tokens = 0;
    this->token_length = malloc(sizeof(int) * this->db.len);
    this->token_type = malloc(sizeof(token_type_e) * this->db.len);
    this->nbr_v = malloc(sizeof(int) * this->db.len);
    this->str_v = malloc(sizeof(char *) * this->db.len);
    this->reg_v = malloc(sizeof(char) * this->db.len);
    CHECK_MALLOC(this->token_length);
    CHECK_MALLOC(this->token_type);
    CHECK_MALLOC(this->nbr_v);
    CHECK_MALLOC(this->str_v);
    CHECK_MALLOC(this->reg_v);
    init_arrays(this);
    return this;
}