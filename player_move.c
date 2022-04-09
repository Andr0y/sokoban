/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void player_up(st_pos *p, char **map)
{
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row - 1, p->col, 'P');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->row -= 1;
}

void player_down(st_pos *p, char **map)
{
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row + 1, p->col, 'P');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->row += 1;
}

void player_right(st_pos *p, char **map)
{
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row, p->col + 1, 'P');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->col += 1;
}

void player_left(st_pos *p, char **map)
{
    mvaddch(p->row, p->col, ' ');
    mvaddch(p->row, p->col - 1, 'P');
    if (map[p->row][p->col] == 'O')
        mvaddch(p->row, p->col, 'O');
    p->col -= 1;
}
