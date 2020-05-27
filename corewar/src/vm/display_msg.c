/*
** EPITECH PROJECT, 2020
** Coreware_vm
** File description:
** Display_message_champion
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

void give_msg_live(champion_t *this)
{
    m_printf("The player %d ", this->id_champ);
    m_printf("(%s) is alive.\n", this->header.prog_name);
}

void give_msg_win(champion_t *this)
{
    m_printf("The player %d ", this->id_champ);
    m_printf("(%s) has won.\n", this->header.prog_name);
}