/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:38:48 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/05 20:39:45 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    game->player_count = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_count++;
                game->x = x;
                game->y = y;
                write(1, "P en (", 6);
                ft_putnbr_fd(game->x, 1);
                write(1, ", ", 2);
                ft_putnbr_fd(game->y, 1);
                write(1, ")\n", 2);
            }
            x++;
        }
        y++;
    }
}
void init_exit_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    game->exit_count = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'E')
            {
                game->exit_count++;
                game->exit_x = x;
                game->exit_y = y;
                write(1, "E en (", 6);
                ft_putnbr_fd(game->exit_x, 1);
                write(1, ", ", 2);
                ft_putnbr_fd(game->exit_y, 1);
                write(1, ")\n", 2);
            }
            x++;
        }
        y++;
    }
}

void init_collectable_count(t_game *game)
{
    int y;
    int x;

    game->count = 0;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'C')
                game->count++;
            x++;
        }
        y++;
    }
    ft_putstr_fd("Consumibles en el mapa: ", 1);
    ft_putnbr_fd(game->count, 1);
    ft_putstr_fd("\n", 1);
}

void component(t_game *game)
{
    init_player_position(game);
    init_exit_position(game);
    init_collectable_count(game);

    if (game->player_count < 1 || game->player_count > 1)
    {
        ft_putstr_fd("Error: No hay o hay mas de un jugador\n", 1);
        exit(1);
    }

    if (game->exit_count < 1 || game->exit_count > 1)
    {
        ft_putstr_fd("Error: No hay o hay mas de una salida\n", 1);
        exit(1);
    }

    if (game->collectable_count < 1)
    {
        ft_putstr_fd("Error: Mínimo un objeto coleccionable\n", 1);
        exit(1);
    }
}
