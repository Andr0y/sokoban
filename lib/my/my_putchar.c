/*
** EPITECH PROJECT, 2021
** my putchar
** File description:
** xd
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
