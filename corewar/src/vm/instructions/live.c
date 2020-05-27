/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** live.c
*/

#include "utils.h"
#include "vm.h"

static int refresh_forked_champ(champion_t *target, list_t *champions)
{
    while (champions) {
        if (target->id_champ == L_CHAMP(champions)->id_champ)
            L_CHAMP(champions)->say_live = true;
        champions = champions->next;
    }
    return EXEC_SUCCESS;
}

int live(vm_t *this, champion_t *champ, args_t *args)
{
    champion_t *target =
    list_get_from_index(this->champions,args[0].value - 1);

    (void) champ;
    if (target) {
        give_msg_live(target);
        this->counter_live++;
        champ->say_live = true;
        refresh_forked_champ(target, this->champions);
        this->last_champ_live = target;
    }
    return EXEC_SUCCESS;
}