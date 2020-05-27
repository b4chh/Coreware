/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_header_info.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

static void skip_spaces_commands(char const *buffer, int *i)
{
    bool is_white_space = true;

    while (is_white_space) {
        switch (buffer[*i]) {
            case ' ':
            case '\r':
            case '\t':
            case '\n':
                (*i)++;
                break;
            default:
                is_white_space = false;
        }
    }
}

static int get_comment(header_t *header, char const *buffer, bool *got_comment)
{
    int i = 0;
    int j = 0;

    if (m_strncmp(COMMENT_CMD, buffer, m_strlen(COMMENT_CMD)) != 0)
        return EXEC_FAIL;
    i += m_strlen(COMMENT_CMD);
    if (buffer[i] != ' ')
        return EXEC_FAIL;
    skip_spaces_commands(buffer, &i);
    CHECK_FALSE(buffer[i] == '"')
    i++;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        if (j == COMMENT_LENGTH)
            return EXEC_FAIL;
        header->comment[j++] = buffer[i++];
    }
    CHECK_FALSE(buffer[i] != '\0')
    *got_comment = true;
    return EXEC_SUCCESS;
}

static int get_name(header_t *header, char const *buffer, bool *got_name)
{
    int i = 0;
    int j = 0;

    if (m_strncmp(NAME_CMD, buffer, m_strlen(NAME_CMD)) != 0)
        return EXEC_FAIL;
    i += m_strlen(NAME_CMD);
    if (buffer[i] != ' ')
        return EXEC_FAIL;
    skip_spaces_commands(buffer, &i);
    CHECK_FALSE(buffer[i] == '"')
    i++;
    while (buffer[i] != '"' && buffer[i] != '\0') {
        if (j == PROG_NAME_LENGTH)
            return EXEC_FAIL;
        header->prog_name[j++] = buffer[i++];
    }
    CHECK_FALSE(buffer[i] != '\0')
    *got_name = true;
    return EXEC_SUCCESS;
}

int get_header_info(tokenizer_t *this)
{
    header_t header = {.magic = COREWAR_EXEC_MAGIC, .prog_size = 0};
    bool first_line = true, got_name = false, got_cmt = false;
    char *buf = NULL;

    m_memset(header.prog_name, 0, 129);
    m_memset(header.comment, 0, 2049);
    for (int j = 0; j < this->nb_lines && (!got_cmt || !got_name); j++) {
        buf = this->info_tokens[j]->db.buffer;
        if (empty_string(buf))
            continue;
        if (first_line && !got_name)
            CHECK_ERR(get_name(&header, buf, &got_name))
        if (!first_line && got_name)
            CHECK_ERR(get_comment(&header, buf, &got_cmt))
        first_line = false;
    }
    CHECK_FALSE(got_name && got_cmt)
    this->header_info = header;
    return EXEC_SUCCESS;
}