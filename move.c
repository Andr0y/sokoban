/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int can_move(int row, int col, char **map, list_box_t **box)
{
    if (is_box(row, col, box) != NULL)
        return 0;
    if (map[row][col] == '#')
        return 0;
    return 1;
}

void move_up(st_pos *p,char **map, list_box_t **box)
{
    if (can_move(p->row - 1, p->col, map, box)) {
        player_up(p, map);
        return;
    }
    if (is_box(p->row - 1 , p->col, box)) {
        if (can_move(p->row - 2, p->col, map, box))
            box_up(map, p, box);
    }
    refresh();
}

void move_down(st_pos *p, char **map, list_box_t **box)
{
    if (can_move(p->row + 1, p->col, map, box)) {
        player_down(p, map);
        return;
    }
    if (is_box(p->row + 1, p->col, box)) {
        if (can_move(p->row + 2, p->col, map, box))
            box_down(map, p, box);
    }
    refresh();
}

void move_right(st_pos *p, char **map, list_box_t **box)
{
    if (can_move(p->row, p->col + 1, map, box)) {
        player_right(p, map);
        return;
    }
    if (is_box(p->row, p->col + 1, box)) {
        if (can_move(p->row, p->col + 2, map, box))
            box_right(map, p, box);
    }
    refresh();
}

void move_left(st_pos *p, char **map, list_box_t **box)
{
    if (can_move(p->row, p->col - 1, map, box)) {
        player_left(p, map);
        return;
    }
    if (is_box(p->row, p->col - 1, box)) {
        if (can_move(p->row, p->col - 2, map, box))
            box_left(map, p, box);
    }
    refresh();
}
