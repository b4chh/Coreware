/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** bytes_label_after.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

int find_value_label_after(parser_t *this)
{
    info_t **tokens = this->tokens->info_tokens;
    int count_bytes = 0, save = 0, max_tokens = 0;

    for (int line = this->curr_line; line < this->nb_lines; line++, save = 0) {
        if (empty_string(tokens[line]->db.buffer) ||
            is_valid_cmd(tokens[line]->db.buffer))
            continue;
        max_tokens = tokens[line]->curr_token;
        CHECK_ERR(explore_token_bytes(tokens, line, &save))
        CHECK_SUCCESS(check_found_label_after_one(this, line, count_bytes))
        if (check_found_label_after_two(this, line, max_tokens)) {
            tokens[this->curr_line]->nbr_v[this->index_token] =
            count_bytes + save;
            return EXEC_SUCCESS;
        }
        count_bytes += save;

    }
    return EXEC_FAIL;
}