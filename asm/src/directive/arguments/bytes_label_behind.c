/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** bytes_label.c
*/

#include "utils.h"
#include "asm.h"

int count_bytes_token(op_t op, token_type_e token, int index_arg)
{
    if (is_indexes_op(op.op_type))
        return get_arg_size_indexed_op(op.op_type, token, index_arg);
    else
        return get_type_arg_from_token(token);
}

int goto_op(token_type_e *tokens, int *ind_token, int _max)
{
    while (*ind_token <= _max && tokens[*ind_token] != MNE_TOKEN)
        (*ind_token)++;
    return EXEC_SUCCESS;
}

int explore_token_bytes(info_t **tokens, int tmp_line, int *count_bytes)
{
    op_t op;
    int ind_token = 0, nb_tokens = tokens[tmp_line]->curr_token;

    CHECK_ERR(goto_op(tokens[tmp_line]->token_type, &ind_token, nb_tokens));
    CHECK_TRUE(ind_token > nb_tokens)
    *count_bytes += 1;
    CHECK_FALSE(tokens[tmp_line]->str_v[ind_token])
    CHECK_ERR(get_operation(tokens[tmp_line]->str_v[ind_token], &op))
    ind_token++;
    if (op.op_type != LIVE && op.op_type != ZJMP && op.op_type != FORK
    && op.op_type != LFORK)
        *count_bytes += 1;
    for (int i = 0; ind_token <= nb_tokens; ind_token++, i++) {
        if (tokens[tmp_line]->token_type[ind_token] == LBL_OPT_TOKEN)
            break;
        *count_bytes +=
        count_bytes_token(op, tokens[tmp_line]->token_type[ind_token], i);
    }
    return EXEC_SUCCESS;
}

int find_value_label_behind(parser_t *this)
{
    info_t **tokens = this->tokens->info_tokens;
    int count_bytes = 0, save = 0, max_tokens = 0;

    for (int line = this->curr_line - 1; line >= 0; line--, save = 0) {
        if (empty_string(tokens[line]->db.buffer) ||
            is_valid_cmd(tokens[line]->db.buffer))
            continue;
        max_tokens = tokens[line]->curr_token;
        CHECK_ERR(explore_token_bytes(tokens, line, &save))
        CHECK_SUCCESS(check_found_label_before_one(this, line, count_bytes,
        save))
        CHECK_SUCCESS(check_found_label_before_two(this, line, count_bytes,
        max_tokens))
        count_bytes += save;
    }
    return EXEC_FAIL;
}