/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
        size += my_putchar(str[i]);
    return size;
}
