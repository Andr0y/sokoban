/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i;
    int size;

    size = my_strlen(dest);
    for (i = 0; src[i] != '\0'; i++)
        dest[size + i] = src[i];
    dest[size + i] = '\0';
    return dest;
}
