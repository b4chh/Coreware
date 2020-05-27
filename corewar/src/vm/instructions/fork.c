/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** fork.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

void list_push_after_tag(list_t **list, void *element, char const *tag,
char const *after)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *curr = *list;
    list_t *prev = NULL;

    node->element = element;
    node->tag = m_strdup(tag);
    while (curr && m_strcmp(curr->tag, after) != 0) {
        prev = curr;
        curr = curr->next;
    }
    (prev) ? prev->next = node : 0;
    node->next = curr;
}

int fork_op(vm_t *this, champion_t *champ, args_t *args)
{
    int n_addr = IND(champ, args[0].value) % IDX_MOD;
    champion_t *child = duplicate_champion(champ);

    CHECK_NULL(child)
    child->pos = n_addr;
    child->reg[PC_IDX] = n_addr;
    list_push(&this->champions, child, child->header.prog_name);
    this->nb_champions++;
    return EXEC_SUCCESS;
}