/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_correct_pattern.c
*/

#include "utils.h"
#include "vm.h"

static bool is_same_args_pattern(args_t *args, args_type_t const *types)
{
    int i = 0;

    for (i = 0; i < args[i].op.nbr_args; i++) {
        if (args[i].type != types[i])
            return false;
    }
    return true;
}

int (*get_correct_pattern(pattern_op_t const *patterns,
const int nb_patterns, args_t *args))(vm_t *, champion_t *, args_t *)
{
    int i = 0;

    for (i = 0; i < nb_patterns; i++) {
        if (is_same_args_pattern(args, patterns[i].types))
            return patterns[i].callback;
    }
    return NULL;
}