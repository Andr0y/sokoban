/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void box_up(char **map, st_pos *p, list_box_t **box)
{
    list_box_t *ptr;

    ptr = is_box(p->row - 1, p->col, box);
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row - 1, p->col, 'P');
    mvaddch(p->row - 2, p->col, 'X');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    ptr->pos->row -= 1;
    p->row -= 1;
}

void box_down(char **map, st_pos *p, list_box_t **box)
{
    list_box_t *ptr;

    ptr = is_box(p->row + 1, p->col, box);
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row + 1, p->col, 'P');
    mvaddch(p->row + 2, p->col, 'X');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->row += 1;
    ptr->pos->row += 1;
}

void box_right(char **map, st_pos *p, list_box_t **box)
{
    list_box_t *ptr;

    ptr = is_box(p->row, p->col + 1, box);
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row, p->col + 1, 'P');
    mvaddch(p->row, p->col + 2, 'X');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->col += 1;
    ptr->pos->col += 1;
}

void box_left(char **map, st_pos *p, list_box_t **box)
{
    list_box_t *ptr;

    ptr = is_box(p->row, p->col - 1, box);
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row, p->col - 1, 'P');
    mvaddch(p->row, p->col - 2, 'X');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->col -= 1;
    ptr->pos->col -= 1;
}
