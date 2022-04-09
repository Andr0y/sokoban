/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int stuck_up_down(char **map, list_box_t *box)
{
    if (map[box->pos->row][box->pos->col] == 'O')
        return 0;
    if (map[box->pos->row - 1][box->pos->col] == '#') {
        if (map[box->pos->row][box->pos->col - 1] == '#')
            return 1;
        if (map[box->pos->row][box->pos->col + 1] == '#')
            return 1;
    }
    if (map[box->pos->row + 1][box->pos->col] == '#') {
        if (map[box->pos->row][box->pos->col - 1] == '#')
            return 1;
        if (map[box->pos->row][box->pos->col + 1] == '#')
            return 1;
    }
    return 0;
}

int stuck_left_right(char **map, list_box_t *box)
{
    if (map[box->pos->row][box->pos->col] == 'O')
        return 0;
    if (map[box->pos->row][box->pos->col + 1] == '#') {
        if (map[box->pos->row + 1][box->pos->col] == '#')
            return 1;
        if (map[box->pos->row - 1][box->pos->col] == '#')
            return 1;
    }
    if (map[box->pos->row][box->pos->col - 1] == '#') {
        if (map[box->pos->row + 1][box->pos->col] == '#')
            return 1;
        if (map[box->pos->row - 1][box->pos->col] == '#')
            return 1;
    }
    return 0;
}
