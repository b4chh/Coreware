/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** list_push_to.c
*/

#include <stdlib.h>
#include "list.h"
#include "../my/my.h"

void list_push_to(list_t **list, void *element, char const *tag, int n)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *prev = NULL;
    list_t *curr = *list;

    if (!node || list_get_length(*list) < n)
        return;
    node->element = element;
    node->tag = m_strdup(tag);
    for (int i = 0; i < n && curr; i++) {
        prev = curr;
        curr = curr->next;
    }
    (prev) ? prev->next = node : 0;
    node->next = curr;
}