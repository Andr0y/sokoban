/*
** EPITECH PROJECT, 2022
** solo
** File description:
** solo
*/

#include "my.h"

int index_to_alpha(char *str, int i)
{
    while (!(my_is_alpha(str[i])) && str[i] != '\0')
        i++;
    return i;
}

int skip_to_next_word(char *str, int i)
{
    while (my_is_alpha(str[i]) && str[i] != '\0')
        i++;
    if (str[i] != '\0')
        i = index_to_alpha(str, i);
    return i;
}

int count_words(char *str)
{
    int count = 0;
    int i = 0;

    i = index_to_alpha(str, i);
    while (str[i]) {
        if (my_is_alpha(str[i])) {
            count++;
            i = skip_to_next_word(str, i);
        }
    }
    return count;
}
