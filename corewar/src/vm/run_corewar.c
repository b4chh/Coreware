/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** run_corewar.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

static bool are_players_alive(vm_t *this, list_t *champ)
{
    int i = 0;

    while (champ != NULL) {
        if (!L_CHAMP(champ)->say_live)
            list_remove_from_index(&this->champions,
            i, destroy_champion);
        else
            L_CHAMP(champ)->say_live = false;
        champ = champ->next;
        i++;
    }
    this->nb_champions = list_get_length(this->champions);
    if (this->nb_champions > 1) {
        this->total_cycles -= CYCLE_DELTA;
        return true;
    }
    return false;
}

static void cycle_champion(vm_t *this)
{
    list_t *champ = this->champions;
    int c_cycle = 0;

    for (c_cycle = 0; this->total_cycles > 0; c_cycle++) {
        while (champ) {
            launch_instruction(this, L_CHAMP(champ));
            champ = champ->next;
        }
        champ = this->champions;
        if (this->is_dump && c_cycle != 0 && !(c_cycle % this->cycle_to_dump))
            show_mem(this->memory, MEM_SIZE);
        if (this->counter_live != 0 && this->counter_live % NBR_LIVE == 0) {
            if (!are_players_alive(this, this->champions))
                break;
            this->counter_live = 0;
        }
    }
}

int run_corewar(vm_t *this)
{
    cycle_champion(this);
    if (list_get_length(this->champions) == 2) {
        give_msg_win(L_CHAMP(this->champions));
        return EXEC_SUCCESS;
    }
    if (!this->last_champ_live)
        return EXEC_FAIL;
    give_msg_win(this->last_champ_live);
    return EXEC_SUCCESS;
}
