/*
** EPITECH PROJECT, 2021
** bin base
** File description:
** bin
*/

#include "my.h"
#include <stdlib.h>

int put_hex_base(int num, char x)
{
    int tmp = 0;
    int i = 0;
    int size = 0;
    char *str;

    str = malloc(sizeof(char) * 9);
    str[8] = '\0';
    for (; num != 0; i++) {
        tmp = num % 16;
        if (tmp < 10)
            str[i] = tmp + '0';
        else
            str[i] = tmp + x - 33;
        num /= 16;
    }
    str[i + 1] = '\0';
    my_revstr(str);
    size = my_putstr(str);
    free(str);
    return size;
}
