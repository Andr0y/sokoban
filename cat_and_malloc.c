/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

char *cat_and_malloc(char *map, char *src)
{
    int size = 0;
    char *res = NULL;

    if (!(map)) {
        res = malloc(sizeof(char) * (1 + my_strlen(src)));
        my_strcpy(res, src);
        free(src);
        return res;
    }
    size = (my_strlen(map) + my_strlen(src) + 1);
    res = malloc(sizeof(char) * size);
    my_strcpy(res, map);
    my_strcat(res, src);
    free(map);
    free(src);
    map = NULL;
    return res;
}
