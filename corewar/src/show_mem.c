/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** show_mem.c
*/

#include "utils.h"
#include "my.h"

int print_base(int nbr, char const *base, int depth)
{
    if (nbr >= m_strlen(base)) {
        print_base(nbr / m_strlen(base), base, depth + 1);
        print_base(nbr % m_strlen(base), base, depth + 1);
    } else {
        if (depth == 0 && nbr < BYTE_PER_LINE)
            m_putchar('0');
        m_putchar(base[nbr]);
    }
    return EXEC_SUCCESS;
}

static int padding(int nbr)
{
    int i = 0;
    int j = 0;
    int nb_zero = 0;

    for (j = BYTE_PER_LINE, i = 0; j <= nbr; i++) {
        j = BYTE_PER_LINE;
        j = m_pow(j, i);
    }
    nb_zero = 8 - (i == 0) ? 2 : i;
    for (i = 0; i < nb_zero; i++)
        m_putchar('0');
    print_base(nbr, "0123456789abcdef", 0);
    return EXEC_SUCCESS;
}

static int align_grid(int read)
{
    int i = 0;
    int tmp = (BYTE_PER_LINE - read) * 3;

    for (i = 0; i < tmp; i++)
        m_putchar(' ');
    return EXEC_SUCCESS;
}

static int show_line(__u_char const *mem, int line, int to_read)
{
    int i = 0;

    padding(line * BYTE_PER_LINE);
    m_putchar(' ');
    for (i = 0; i < to_read; i++) {
        m_putchar(' ');
        (i == 16) ? m_putchar(' ') : 0;
        print_base((int) mem[line * BYTE_PER_LINE + i],
        "0123456789abcdef", 0);
    }
    align_grid(to_read);
    m_printf("  |");
    for (i = 0; i < to_read; i++) {
        is_printable(mem[line * BYTE_PER_LINE + i])
        ? m_putchar(mem[line * BYTE_PER_LINE + i])
        : m_putchar('.');
    }
    m_printf("|\n");
    return EXEC_SUCCESS;
}

int show_mem(__u_char const *mem, int size)
{
    int i = 0;
    int tmp = 0;

    for (i = 0; (i + 1) * BYTE_PER_LINE < size; i++)
        show_line(mem, i, BYTE_PER_LINE);
    tmp = size - i * BYTE_PER_LINE;
    if (tmp) {
        show_line(mem, i, tmp);
        padding(i * BYTE_PER_LINE + tmp);
        m_putchar('\n');
    }
    return EXEC_SUCCESS;
}