/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** load_mem.c
*/

#include "utils.h"
#include "vm.h"
#include "my.h"

int get_champ_size(list_t *champ)
{
    int sum = 0;

    while (champ != NULL) {
        sum += ((champion_t *) champ->element)->header.prog_size;
        champ = champ->next;
    }
    return (sum);
}

int set_memory(vm_t *this)
{
    list_t *champ = this->champions;
    int space = 0;
    int i = 0;

    m_memset(this->memory, '\0', MEM_SIZE);
    CHECK_FALSE(get_champ_size(this->champions) < MEM_SIZE);
    space = MEM_SIZE / this->nb_champions * (this->nb_champions - 1);
    while (champ != NULL) {
        m_memcpy(CIRCULAR(this->memory + (i * space)),
        L_CHAMP(champ)->bytecode,
        L_CHAMP(champ)->header.prog_size);
        L_CHAMP(champ)->reg[PC_IDX] = i * space;
        L_CHAMP(champ)->pos = i * space;
        champ = champ->next;
        i++;
    }
    return EXIT_SUCCESS;
}