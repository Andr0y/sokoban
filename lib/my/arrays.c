/*
** EPITECH PROJECT, 2022
** solo
** File description:
** solo
*/

#include <stdlib.h>
#include "my.h"

int my_is_alpha(char c)
{
    if (c == 10 || c == 9 || c == 0)
        return 0;
    return 1;
}

char **malloc_tab(int lines, char *str)
{
    int i;
    char **tab;

    tab = malloc(sizeof(char *) * (lines + 1));
    for (i = 0; i < lines; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    }
    tab[i] = NULL;
    return tab;
}

void copy_next_word(char **dest, int k, char *src, int i)
{
    int j = 0;

    while (my_is_alpha(src[i])) {
        dest[k][j] = src[i];
        i++;
        j++;
    }
    dest[k][j] = '\0';
}

char **words_to_tab(char *str)
{
    int j = 0;
    char **tab;
    int i = 0;

    tab = malloc_tab(count_words(str), str);
    i = index_to_alpha(str, i);
    while (str[i]) {
        copy_next_word(tab, j, str, i);
        i = skip_to_next_word(str, i);
        j++;
    }
    return tab;
}
