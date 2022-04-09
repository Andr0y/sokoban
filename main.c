/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int help(void)
{
    my_printf("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file ");
    my_printf("representing the warehouse map, containing '#' for ");
    my_printf("walls, 'P' for the player, 'X' for boxes and 'O' for ");
    my_printf("storage locations.\n");
    return 0;
}

int main(int ac, char **av)
{
    int win = 0;
    char *map_str;
    map_data_t *data = NULL;

    if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'h')
        return help();
    if (ac != 2)
        return 84;
    data = init_map_data();
    if (ac == 2)
        if ((map_str = check_map(av[1], data)) == NULL) {
            write(2, "Invalid map\n", 12);
            free(data);
            return 84;
        }
    free(data);
    win = init_sokoban(map_str);
    endwin();
    return win;
}
