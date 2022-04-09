/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_size = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i <= str_size / 2; i++) {
        temp = str[i];
        str[i] = str[str_size - i];
        str[str_size - i] = temp;
    }
    return str;
}
