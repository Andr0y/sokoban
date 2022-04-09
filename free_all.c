/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void free_2d_array(char **map)
{
    int i = 0;

    while (map[i]) {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
    map = NULL;
}

void free_targets(list_tgt_t **box)
{
    list_tgt_t *tmp;

    while ((*box)) {
        tmp = (*box);
        (*box) = (*box)->next;
        free(tmp->pos);
        free(tmp);
    }
}

void free_boxes(list_box_t **box)
{
    list_box_t *tmp;

    while ((*box)) {
        tmp = (*box);
        (*box) = (*box)->next;
        free(tmp->pos);
        free(tmp);
    }
}

void free_all(char **map, list_box_t **box, list_tgt_t **tgt, st_pos *p)
{
    free_2d_array(map);
    free_boxes(box);
    free_targets(tgt);
    free(p);
}
