/*
** EPITECH PROJECT, 2021
** header my_printf
** File description:
** header my_printf
*/

#ifndef MY_H
    #define MY_H

int my_is_alpha(char c);
char **malloc_tab(int lines, char *str);
void copy_next_word(char **dest, int k, char *src, int i);
char **words_to_tab(char *str);
int index_to_alpha(char *str, int i);
int skip_to_next_word(char *str, int i);
int count_words(char *str);
int my_dumb_strlen(char const *str, int pos);
int get_tab_width(char const *str);
int is_separator(char c);
int big_s(char *str);
int put_hex_base(int num, char x);
int put_octal_base(int num);
char *my_revstr(char *str);
int my_atoi(char *str);
int put_bin_base(int num);
int my_printf(const char *format, ...);
int my_putchar(char c);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
int my_putstr(char const *str);
int my_put_nbr(long nb);
int my_strlen(char *str);

#endif
