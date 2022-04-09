/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int is_same_pos(list_box_t *box, list_tgt_t *tgt)
{
    if ((box->pos->col == tgt->pos->col) && (box->pos->row == tgt->pos->row))
        return 1;
    return 0;
}

int check_lose(list_box_t **boxes, char **map)
{
    list_box_t *tmp = (*boxes);

    while (tmp) {
        if (stuck_left_right(map, tmp) || stuck_up_down(map, tmp))
            tmp = tmp->next;
        else
            return 0;
    }
    return 1;
}

int check_win(list_box_t **boxes, list_tgt_t **targets)
{
    int ok = 0;
    list_box_t *box = (*boxes);
    list_tgt_t *tgt = (*targets);

    while (tgt) {
        while (box) {
            ok += is_same_pos(box, tgt);
            box = box->next;
        }
        tgt = tgt->next;
        box = (*boxes);
    }
    if (ok == target_amount(targets)) {
        return 1;
    }
    return 0;
}
