/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:26:21 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/10 18:26:23 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **create_map_copy(t_game *game)
{
    char **map_copy;
    int i;

    map_copy = malloc(game->height * sizeof(char *));
    if (!map_copy)
        return NULL;

    i = 0;
    while (i < game->height)
    {
        map_copy[i] = malloc(game->width * sizeof(char));
        if (!map_copy[i])
        {
            while (i-- > 0)
                free(map_copy[i]);
            free(map_copy);
            return NULL;
        }
        ft_memcpy(map_copy[i], game->map[i], game->width * sizeof(char));
        i++;
    }

    return map_copy;
}

void free_map_copy(char **map_copy, t_game *game)
{
    int i;

    i = 0;
    while (i < game->height) {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
}

int check_exit_accessible(t_game *game, char **map_copy)
{
    if (map_copy[game->exit_y][game->exit_x] != 'V')
    {
        ft_error("Error: la salida no es accesible\n");
            exit(1);
    }
    return 1;
}

int check_consumables_accessible(t_game *game, char **map_copy)
{
    int y;
    int x;
    
    y = 0;
    while (y < game->height) {
        x = 0;
        while (x < game->width) {
            if (game->map[y][x] == 'C' && map_copy[y][x] != 'V')
            {
                ft_error("Error: consumible no accesible\n");
                exit(1);
            }
            x++;
        }
        y++;
    }
    return 1;
}

int accessible(t_game *game)
{
    char **map_copy;

    map_copy = create_map_copy(game);
    if (!map_copy)
        return 0;

    flood_fill(game, game->x, game->y, map_copy);

    if (!check_exit_accessible(game, map_copy))
    {
        free_map_copy(map_copy, game);
        return 0;
    }

    if (!check_consumables_accessible(game, map_copy))
    {
        free_map_copy(map_copy, game);
        return 0;
    }

    free_map_copy(map_copy, game);
    return 1;
}


