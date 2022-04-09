/*
** EPITECH PROJECT, 2021
** bin base
** File description:
** bin
*/

#include "my.h"
#include <stdlib.h>

int put_octal_base(int num)
{
    int size = 0;
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    str[10] = '\0';
    for (; num != 0; i++) {
        str[i] = '0' + (num % 8);
        num /= 8;
    }
    str[i + 1] = '\0';
    my_revstr(str);
    size = my_putstr(str);
    free(str);
    return size;
}
