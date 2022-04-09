/*
** EPITECH PROJECT, 2022
** header my_sokoban
** File description:
** header my_sokoban
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#ifndef SOKOBAN_H
    #define SOKOBAN_H

typedef struct map_data_t {
    int p;
    int x;
    int o;
}map_data_t;

typedef struct st_pos {
    int col;
    int row;
    int og_col;
    int og_row;
}st_pos;

typedef struct list_tgt_t {
    st_pos *pos;
    struct list_tgt_t *next;
}list_tgt_t;

typedef struct list_box_t {
    st_pos *pos;
    int ok;
    struct list_box_t *next;
}list_box_t;

int stuck_left_right(char **map, list_box_t *box);
int stuck_up_down(char **map, list_box_t *box);
int check_lose(list_box_t **boxes, char **map);
void free_2d_array(char **map);
void free_targets(list_tgt_t **box);
void free_boxes(list_box_t **box);
void free_all(char **map, list_box_t **box, list_tgt_t **tgt, st_pos *p);
int target_amount(list_tgt_t **tgt);
int can_move(int row, int col, char **map, list_box_t **box);
list_box_t *is_box(int row, int col, list_box_t **box);
list_tgt_t *is_tgt(int row, int col, list_tgt_t **tgt);
void box_left(char **map, st_pos *p, list_box_t **box);
void box_right(char **map, st_pos *p, list_box_t **box);
void box_down(char **map, st_pos *p, list_box_t **box);
void box_up(char **map, st_pos *p, list_box_t **box);
void player_up(st_pos *p, char **map);
void player_down(st_pos *p, char **map);
void player_right(st_pos *p, char **map);
void player_left(st_pos *p, char **map);
void move_left(st_pos *p, char **map, list_box_t **box);
void move_right(st_pos *p, char **map, list_box_t **box);
void move_down(st_pos *p, char **map, list_box_t **box);
void move_up(st_pos *p, char **map, list_box_t **box);
void start_ncurse(char **map);
int sokoban(list_box_t **box, list_tgt_t **tgt, st_pos *player, char **map);
void push_pos_tgt(list_tgt_t **head, int row, int col);
void push_pos(list_box_t **head, int row, int col);
int check_map_data(map_data_t *data);
map_data_t *init_map_data(void);
char *cat_and_malloc(char *dest, char *src);
int invalid_char(char c);
void check_char(map_data_t *data, char c);
map_data_t *check_line(char *str, int i, map_data_t *data);
char *check_map(char *filepath, map_data_t *data);
int init_sokoban(char *str);
int check_win(list_box_t **boxes, list_tgt_t **targets);
int is_same_pos(list_box_t *box, list_tgt_t *tgt);

#endif
