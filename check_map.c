/*
** EPITECH PROJECT, 2022
** checkmap
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int invalid_char(char c)
{
    if (c == ' ' || c == '#' || c == 'P' || c == 'X' || c == 'O' || c == '\n')
        return 0;
    write(2, "error, invalid character found in map", 37);
    return 1;
}

void check_char(map_data_t *data, char c)
{
    if (c == 'P')
        data->p += 1;
    if (c == 'O')
        data->o += 1;
    if (c == 'X')
        data->x += 1;
}

map_data_t *check_line(char *str, int i, map_data_t *data)
{
    int j = 0;

    while ((i == 0) && (str[j] != '\0')) {
        if (str[j] == '\n')
            return data;
        if (str[j] != '#')
            return NULL;
        j++;
    }
    if ((str[0] != '#') || str[my_strlen(str) - 2] != '#')
        return NULL;
    for (; str[j] != '\0'; j++) {
        if (invalid_char(str[j]))
            return NULL;
        check_char(data, str[j]);
    }
    return data;
}

int check_map_data(map_data_t *data)
{
    if (data->p != 1)
        return 1;
    if (!((data->x) == (data->o)))
        return 1;
    return 0;
}

char *check_map(char *path, map_data_t *data)
{
    char *map = NULL;
    FILE *stream;
    char *lineptr = NULL;
    size_t n = 0;
    int size = 0;

    stream = fopen(path, "r");
    if (stream == NULL)
        return NULL;
    for (int i = 0; (size = (getline(&lineptr, &n, stream))) != -1; i++) {
        data = check_line(lineptr, i, data);
        if (data == NULL)
            return NULL;
        map = cat_and_malloc(map, lineptr);
        lineptr = NULL;
    }
    free(lineptr);
    if (check_map_data(data))
        return NULL;
    fclose(stream);
    return map;
}
