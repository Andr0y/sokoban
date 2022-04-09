/*
** EPITECH PROJECT, 2021
** bin base
** File description:
** bin
*/

#include "my.h"
#include <stdlib.h>

int remove_zeros(char *str)
{
    int j = 0;
    int i = 0;

    for (; str[i] != '1'; i++) {
        if (str[i] == '\0')
            return 0;
    }
    for (; str[i] != '\0'; i++) {
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';
    return 1;
}

int put_bin_base(int num)
{
    int size = 0;
    int bit = 0;
    int j = 0;
    char *str;

    str = malloc(sizeof(char) * 33);
    str[32] = '\0';
    for (int i = 31; i >= 0; i--) {
        bit = num >> i;
        if (bit & 1)
            str[j] = 1 + '0';
        else
            str[j] = 0 + '0';
        j++;
    }
    remove_zeros(str);
    size = my_putstr(str);
    free(str);
    return size;
}
