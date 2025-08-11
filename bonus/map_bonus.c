/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:30:34 by ksudyn            #+#    #+#             */
/*   Updated: 2025/08/11 17:52:52 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void   draw_steps(t_game *game)
{
    char    *steps_str;
    int     x;
    int     y;

    steps_str =ft_itoa(game->step);
    if(!steps_str)
        return ;
    x = (game->width - 1) * CELL_SIZE;
    y = (game->height - 1) * CELL_SIZE;
    mlx_string_put(game->mlx, game->win, x, y, 0x4B0082, steps_str);
    free(steps_str);
}

void	draw_wall(t_game *game, int x, int y)
{
	t_images	*imgs;

	imgs = &game->images;
	// Comprobar si es una esquina
	if (x == 0 && y == 0)
		draw_image(game, imgs->wall_corner_top_left, x, y);
	else if (x == game->width - 1 && y == 0)
		draw_image(game, imgs->wall_corner_top_right, x, y);
	else if (x == 0 && y == game->height - 1)
		draw_image(game, imgs->wall_corner_bottom_left, x, y);
	else if (x == game->width - 1 && y == game->height - 1)
		draw_image(game, imgs->wall_corner_bottom_right, x, y);
	// Comprobar si es un borde
	else if (y == 0)
		draw_image(game, imgs->wall_horizontal, x, y);	// Borde superior
	else if (y == game->height - 1)
		draw_image(game, imgs->wall_horizontal, x, y);	// Borde inferior
	else if (x == 0)
		draw_image(game, imgs->wall_vertical, x, y);	// Borde izquierdo
	else if (x == game->width - 1)
		draw_image(game, imgs->wall_vertical, x, y);	// Borde derecho
	// Cualquier otro muro interior
	else
		draw_image(game, imgs->wall_img, x, y);
}

void	draw_tile_bonus(t_game *game, char tile, int x, int y)
{
	t_images	*imgs;

	imgs = &game->images;
	// Verificar si alguna imagen es NULL antes de dibujar
	if (!imgs->player_img || !imgs->exit_img || !imgs->collectable_img
		|| !imgs->nothing_img || !imgs->wall_img
		|| !imgs->wall_corner_top_left || !imgs->wall_corner_top_right
		|| !imgs->wall_corner_bottom_left || !imgs->wall_corner_bottom_right
		|| !imgs->wall_horizontal || !imgs->wall_vertical)
	{
		write(2, "Error: Una o más imágenes son NULL\n", 34);
		exit(EXIT_FAILURE);
	}
	if (tile == '1')
		draw_wall(game, x, y);
	else if (tile == '0')
		draw_image(game, imgs->nothing_img, x, y);
	else if (tile == 'C')
		draw_image(game, imgs->collectable_img, x, y);
	else if (tile == 'E')
		draw_image(game, imgs->exit_img, x, y);
	else if (tile == 'P')
		draw_image(game, game->player_texture, x, y);
	else if(tile == 'X')
		draw_image(game, imgs->enemy_img, x, y);
}

void	draw_map_bonus(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->mlx || !game->win)
		return ;
	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile_bonus(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	draw_steps(game);
}
