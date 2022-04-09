/*
** EPITECH PROJECT, 2022
** init_sokoban
** File description:
** init sokoban
*/

#include "my.h"
#include "sokoban.h"

void find_pos(list_box_t **box, list_tgt_t **tgt, st_pos *player, char **map)
{
    int col = 1;
    int row = 1;

    while (map[row]) {
        if (map[row][col] == 'X')
            push_pos(box, row, col);
        if (map[row][col] == 'O')
            push_pos_tgt(tgt, row, col);
        if (map[row][col] == 'P') {
            player->col = col;
            player->row = row;
        }
        if (map[row][col + 1] == '\0') {
            row++;
            col = 0;
        }
        col++;
    }
}

int init_sokoban(char *str)
{
    int res = 0;
    char **map;
    st_pos *player_pos = malloc(sizeof(st_pos));
    list_box_t *box = NULL;
    list_tgt_t *tgt = NULL;

    map = words_to_tab(str);
    free(str);
    find_pos(&box, &tgt, player_pos, map);
    player_pos->og_col = player_pos->col;
    player_pos->og_row = player_pos->row;
    box->pos->og_col = box->pos->col;
    box->pos->og_row = box->pos->row;
    res = sokoban(&box, &tgt, player_pos, map);
    free_all(map, &box, &tgt, player_pos);
    return res;
}
