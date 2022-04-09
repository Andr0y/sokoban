/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void push_pos(list_box_t **head, int row, int col)
{
    list_box_t *new_box;

    new_box = malloc(sizeof(list_box_t));
    new_box->pos = malloc(sizeof(st_pos));
    new_box->pos->col = col;
    new_box->pos->row = row;
    new_box->next = (*head);
    (*head) = new_box;
}

void push_pos_tgt(list_tgt_t **head, int row, int col)
{
    list_tgt_t *new_tgt;

    new_tgt = malloc(sizeof(list_tgt_t));
    new_tgt->pos = malloc(sizeof(st_pos));
    new_tgt->pos->col = col;
    new_tgt->pos->row = row;
    new_tgt->next = (*head);
    (*head) = new_tgt;
}
