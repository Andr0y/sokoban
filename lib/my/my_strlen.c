/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** returns the size of a string
*/

#include "my.h"

int my_strlen(char *str)
{
    int size = 0;

    if (!(str))
        return 0;
    while (str[size] != '\0')
        size++;
    return size;
}
