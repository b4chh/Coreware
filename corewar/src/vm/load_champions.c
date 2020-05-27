/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** load_champions.c
*/

#include "utils.h"
#include "vm.h"

static bool is_available_nbr(int nbr, list_t *params, list_t *champions)
{
    bool not_found = true;

    while (params) {
        not_found = L_PARAM(params)->prog_nbr != nbr;
        if (not_found)
            break;
        params = params->next;
    }
    while (champions) {
        not_found = L_CHAMP(champions)->id_champ != nbr;
        if (!not_found)
            break;
        champions = champions->next;
    }
    return not_found;
}

static int get_prog_nbr(list_t *params, list_t *champions)
{
    int nbr = 1;

    while (!is_available_nbr(nbr, params, champions))
        nbr++;
    return nbr;
}

static int is_valid(int magic)
{
    return magic == COREWAR_EXEC_MAGIC;
}

int load_champions(vm_t *this)
{
    list_t *params = this->params;
    FILE *bin = NULL;
    champion_t *tmp = NULL;

    while (params) {
        CHECK_NULL(bin = fopen(L_PARAM(params)->path, "r"))
        CHECK_NULL(tmp = create_champion(
                (L_PARAM(params)->prog_nbr == AUTO_NBR)
                ? get_prog_nbr(this->params, this->champions)
                : L_PARAM(params)->prog_nbr, bin)
        )
        CHECK_ERR(is_valid(tmp->header.magic))
        list_push(&this->champions, tmp, tmp->header.prog_name);
        fclose(bin);
        params = params->next;
    }
    this->nb_champions = list_get_length(this->champions);
    this->champions = list_reverse(this->champions);
    return EXEC_SUCCESS;
}
