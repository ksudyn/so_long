/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:01:53 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/11 17:06:51 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*collectable_img;
void	*exit_img;
void	*nothing_img;
void	*player_img;
void	*wall_img;

void	ft_load_img(void *mlx)
{
	collectable_img = load_graphics(mlx, COLLECTABLE);
	exit_img = load_graphics(mlx, EXIT);
	nothing_img = load_graphics(mlx, NOTHING);
	player_img = load_graphics(mlx, PLAYER);
	wall_img = load_graphics(mlx, WALL);
	if (!collectable_img || !exit_img || !nothing_img
		|| !player_img || !wall_img)
	{
		ft_putstr_fd("Error: F al leer las imagenes.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_reset_data(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->x = 0;
	game->y = 0;
	game->count = 0;
	game->step = 0;
	game->finish = 0;
}
