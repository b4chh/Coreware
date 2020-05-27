/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** run_parser.c
*/

#include "utils.h"
#include "asm.h"

int get_index_start_op(parser_t *this)
{
    int len = this->tokens->info_tokens[this->curr_line]->db.len;

    while (this->index_token < len
    && this->tokens->info_tokens[this->curr_line]
    ->token_type[this->index_token] != MNE_TOKEN)
        this->index_token++;
    if (this->index_token == len)
        this->index_token = -1;
    return this->index_token;
}

int get_prog_size(parser_t *this)
{
    int i = 0;
    this->tokens->header_info.prog_size = 0;

    for (i = 0; i < this->nb_lines; i++) {
        if (empty_string(this->tokens->info_tokens[i]->db.buffer) ||
            is_valid_cmd(this->tokens->info_tokens[i]->db.buffer))
            continue;
        explore_token_bytes(
                this->tokens->info_tokens,
                i,
                &this->tokens->header_info.prog_size
        );
    }
    return EXEC_SUCCESS;
}

int run_parser(parser_t *this)
{
    int i = 0;
    op_t op;

    for (i = 0; i < this->nb_lines; i++) {
        if (empty_string(this->tokens->info_tokens[i]->db.buffer) ||
        is_valid_cmd(this->tokens->info_tokens[i]->db.buffer)) {
            this->curr_line += 1;
            continue;
        }
        if (get_index_start_op(this) != -1) {
            CHECK_ERR(get_operation(this->tokens
            ->info_tokens[this->curr_line]->str_v[this->index_token], &op))
            this->cmds[this->curr_line] = create_directive(op);
            this->index_token += 1;
            CHECK_ERR(parse_args(this));
        }
        this->curr_line += 1;
        this->index_token = 0;
    }
    return EXEC_SUCCESS;
}