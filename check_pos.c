/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

list_box_t *is_box(int row, int col, list_box_t **box)
{
    list_box_t *tmp;

    tmp = (*box);
    while (tmp) {
        if ((tmp->pos->col == col) && (tmp->pos->row == row)) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

list_tgt_t *is_tgt(int row, int col, list_tgt_t **tgt)
{
    list_tgt_t *tmp;

    tmp = (*tgt);
    while (tmp) {
        if ((tmp->pos->col == col) && (tmp->pos->row == row))
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
