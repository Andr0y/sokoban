/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

map_data_t *init_map_data(void)
{
    map_data_t *data = malloc(sizeof(map_data_t));

    data->p = 0;
    data->x = 0;
    data->o = 0;
    return data;
}
