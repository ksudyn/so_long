/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:01:53 by ksudyn            #+#    #+#             */
/*   Updated: 2025/08/11 20:42:57 by ksudyn           ###   ########.fr       */
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
	// Cargar imágenes adicionales para muros
	images->wall_corner_top_left = load_graphics(mlx, WALL_CORNER_TOP_LEFT);
	images->wall_corner_top_right = load_graphics(mlx, WALL_CORNER_TOP_RIGHT);
	images->wall_corner_bottom_left = load_graphics(mlx, WALL_CORNER_BOTTOM_LEFT);
	images->wall_corner_bottom_right = load_graphics(mlx, WALL_CORNER_BOTTOM_RIGHT);
	images->wall_horizontal = load_graphics(mlx, WALL_HORIZONTAL);
	images->wall_vertical = load_graphics(mlx, WALL_VERTICAL);
	// Verificación de errores
	if (!images->collectable_img || !images->exit_img || !images->nothing_img
		|| !images->player_img || !images->wall_img
		|| !images->wall_corner_top_left || !images->wall_corner_top_right
		|| !images->wall_corner_bottom_left || !images->wall_corner_bottom_right
		|| !images->wall_horizontal || !images->wall_vertical)
	{
		ft_putstr_fd("Error: Fallo al leer una o más imágenes.\n", 2);
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
