/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** load_params.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

static int get_type_arg(char *option)
{
    if (m_strcmp(option, "-dump") == 0)
        return DUMP;
    return ARG;
}

static void change_ac(int *ac, int type)
{
    if (type == DUMP)
        *ac -= 2;
}

static int set_dump(vm_t *this, char **av, int *idx)
{
    if (m_strcmp(av[*idx], "-dump") != 0)
        return EXEC_SUCCESS;
    *idx += 1;
    CHECK_FALSE(*idx < len_tab(av))
    CHECK_FALSE(m_str_isnum(av[*idx]) && m_getnbr(av[*idx]) >= 0)
    this->is_dump = true;
    this->cycle_to_dump = m_getnbr(av[*idx]);
    *idx += 1;
    return EXEC_SUCCESS;
}

static int check_champ(vm_t *this, int *ac, char **av, int *idx)
{
    param_t *tmp = NULL;
    int tmp_idx = *idx;

    tmp = create_param(AUTO_ADDR, AUTO_NBR, NULL);
    CHECK_NULL(tmp)
    CHECK_ERR(init_prog_nbr(tmp, this, av, idx))
    CHECK_ERR(init_addr(tmp, this, av, idx))
    CHECK_ERR(init_path(tmp, this, av, idx))
    *ac -= (*idx - tmp_idx);
    list_push(&this->params, tmp, NULL);
    return EXEC_SUCCESS;
}

int load_params(vm_t *this, int ac, char **av)
{
    int i = 1;
    int type = 0;

    while (ac != 0) {
        CHECK_ERR(type = get_type_arg(av[i]))
        change_ac(&ac, type);
        CHECK_ARG(ac)
        if (type == ARG) {
            CHECK_ERR(check_champ(this, &ac, av, &i))
        } else
            CHECK_ERR(set_dump(this, av, &i))
    }
    this->params = list_reverse(this->params);
    return EXEC_SUCCESS;
}
