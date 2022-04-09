/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void start_ncurse(char **map)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    for (int i = 0; map[i] != NULL; i++)
        printw("%s\n", map[i]);
    refresh();
}

void reset(list_box_t **box, st_pos *player, char **map)
{
    list_box_t *tmp;

    move(0, 0);
    tmp = (*box);
    while (tmp) {
        tmp->pos->col = tmp->pos->og_col;
        tmp->pos->row = tmp->pos->og_row;
        tmp = tmp->next;
    }
    player->col = player->og_col;
    player->row = player->og_row;
    endwin();
    start_ncurse(map);
}

int target_amount(list_tgt_t **tgt)
{
    int res = 0;
    list_tgt_t *temp;

    temp = (*tgt);
    while (temp) {
        res++;
        temp = temp->next;
    }
    return res;
}

int sokoban(list_box_t **box, list_tgt_t **tgt, st_pos *player, char **map)
{
    int ch = 0;

    start_ncurse(map);
    while ((ch = getch())) {
        if (ch == KEY_UP)
            move_up(player, map, box);
        if (ch == KEY_DOWN)
            move_down(player, map, box);
        if (ch == KEY_RIGHT)
            move_right(player, map, box);
        if (ch == KEY_LEFT)
            move_left(player, map, box);
        if (ch == ' ')
            reset(box, player, map);
        if (check_win(box, tgt))
            return 0;
        if (check_lose(box, map))
            return 1;
        }
    return 0;
}
