/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** displays an int and returns its length
*/

#include "my.h"

int abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

void display_limit(void)
{
    my_putchar('-');
    my_putchar('0' + 2);
    my_putchar('0' + 1);
    my_putchar('0' + 4);
    my_putchar('0' + 7);
    my_putchar('0' + 4);
    my_putchar('0' + 8);
    my_putchar('0' + 3);
    my_putchar('0' + 6);
    my_putchar('0' + 4);
    my_putchar('0' + 8);
}

int my_put_nbr(long nb)
{
    int size = 0;

    if (nb == -2147483648) {
        display_limit();
        return (10);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = abs(nb);
    }
    if (nb < 10 && nb > -10) {
        my_putchar('0' + nb);
        return (1);
    }
    size = my_put_nbr(nb / 10);
    my_putchar('0' + nb % 10);
    return (1 + size);
}
