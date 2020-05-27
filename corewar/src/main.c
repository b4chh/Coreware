/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main corewar
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

static int display_usage(int ac, char **av)
{
    if (ac == 2 && m_strcmp(av[1], "-h") == 0) {
        m_printf(USAGE);
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

int main(int ac, char **av)
{
    vm_t *vm = NULL;

    CHECK_SUCCESS(display_usage(ac, av));
    CHECK_FALSE(ac >= 3)
    CHECK_NULL(vm = create_vm());
    CHECK_ERR(load_params(vm, ac - 1, av))
    CHECK_ERR(load_champions(vm));
    CHECK_ERR(set_memory(vm));
    run_corewar(vm);
    destroy_vm(vm);
    return EXEC_SUCCESS;
}