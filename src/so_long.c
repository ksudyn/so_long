/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:01:53 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/20 15:26:25 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_img(void *mlx, t_images *images)
{
	images->collectable_img = load_graphics(mlx, COLLECTABLE);
	images->exit_img = load_graphics(mlx, EXIT);
	images->nothing_img = load_graphics(mlx, NOTHING);
	images->player_img = load_graphics(mlx, PLAYER);
	images->wall_img = load_graphics(mlx, WALL);
	if (!images->collectable_img || !images->exit_img || !images->nothing_img
		|| !images->player_img || !images->wall_img)
	{
		ft_putstr_fd("Error: Fallo al leer las imágenes.\n", 2);
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
