/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** duplicate_champion.c
*/

#include "utils.h"
#include "my.h"
#include "vm/champion.h"

champion_t *duplicate_champion(champion_t *parent)
{
    champion_t *child = malloc(sizeof(champion_t));

    CHECK_MALLOC(child);
    m_memcpy(child, parent, sizeof(champion_t));
    child->bytecode = NULL;
    child->wait_for_op = 0;
    child->finished = false;
    return child;
}

