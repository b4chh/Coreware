/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** create_champion.c
*/

#include "utils.h"
#include "vm/champion.h"

champion_t *create_champion(int prog_nbr, FILE *bin)
{
    int i = 0;
    champion_t *this = malloc(sizeof(champion_t));

    CHECK_MALLOC(this)
    for (i = 0; i < REG_NUMBER + 1; i++)
        this->reg[i] = (i == 1) ? prog_nbr : 0;
    this->id_champ = this->reg[1];
    this->pos = 0;
    this->wait_for_op = 0;
    this->finished = false;
    this->say_live = false;
    this->carry = false;
    CHECK_ERR_PTR(get_header(bin, &this->header));
    CHECK_ERR_PTR(get_instructions(this, bin, this->header.prog_size));
    return this;
}