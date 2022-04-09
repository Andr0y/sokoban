/*
** EPITECH PROJECT, 2021
** y_strcpy
** File description:
** copies a string into another, dest needs the right size
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int src_size = my_strlen(src);

    if (!(src))
        return dest;
    for (int i = 0; i <= src_size; i++) {
        dest[i] = src[i];
    }
    return dest;
}
