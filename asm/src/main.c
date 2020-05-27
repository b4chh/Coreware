/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** main.c
*/

#include "utils.h"
#include "my.h"
#include "asm.h"

static int run_compilation(int ac, char **av)
{
    char **content = NULL;
    FILE *file = NULL;
    tokenizer_t *tokenizer = NULL;
    int nb_lines = 0;

    for (int i = 1; i < ac; i++) {
        file = fopen(av[i], "r");
        CHECK_NULL(file)
        nb_lines = get_length_file(file);
        CHECK_NULL(content = store_file(file, nb_lines))
        CHECK_NULL(tokenizer = create_tokenizer(content, nb_lines));
        CHECK_ERR(run_lexer(tokenizer));
        CHECK_ERR(compile(tokenizer, av[i]));
        fclose(file);
        destroy_tokenizer(tokenizer);
        splitstr_destroy(content);
    }
    return EXEC_SUCCESS;
}

int main(int ac, char **av)
{
    CHECK_FALSE(ac >= 2)
    CHECK_ERR(run_compilation(ac, av))
    return EXEC_SUCCESS;
}