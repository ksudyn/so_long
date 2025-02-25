/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:04:31 by ksudyn            #+#    #+#             */
/*   Updated: 2025/02/25 19:04:34 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	draw_wall(t_game *game, int x, int y)
{
	t_images	*imgs;

	imgs = &game->images;

	// Comprobar si es una esquina
	if (x == 0 && y == 0)
		draw_image(game, imgs->wall_corner_top_left, x, y);
	else if (x == game->map_width - 1 && y == 0)
		draw_image(game, imgs->wall_corner_top_right, x, y);
	else if (x == 0 && y == game->map_height - 1)
		draw_image(game, imgs->wall_corner_bottom_left, x, y);
	else if (x == game->map_width - 1 && y == game->map_height - 1)
		draw_image(game, imgs->wall_corner_bottom_right, x, y);

	// Comprobar si es un borde
	else if (y == 0)
		draw_image(game, imgs->wall_horizontal, x, y); // Borde superior
	else if (y == game->map_height - 1)
		draw_image(game, imgs->wall_horizontal, x, y); // Borde inferior
	else if (x == 0)
		draw_image(game, imgs->wall_vertical, x, y);   // Borde izquierdo
	else if (x == game->map_width - 1)
		draw_image(game, imgs->wall_vertical, x, y);   // Borde derecho

	// Cualquier otro muro interior
	else
		draw_image(game, imgs->wall_img, x, y);
}

void	draw_tile(t_game *game, char tile, int x, int y)
{
	t_images	*imgs;

	imgs = &game->images;

	// Llamar a draw_wall para los muros
	if (tile == '1')
		draw_wall(game, x, y);
	else if (tile == '0')
		draw_image(game, imgs->nothing_img, x, y);
	else if (tile == 'C')
		draw_image(game, imgs->collectable_img, x, y);
	else if (tile == 'E')
		draw_image(game, imgs->exit_img, x, y);
	else if (tile == 'P')
		draw_image(game, imgs->player_img, x, y);

	// Verificar si alguna imagen es NULL
	if (!imgs->player_img || !imgs->exit_img || !imgs->collectable_img
		|| !imgs->nothing_img || !imgs->wall_img
		|| !imgs->wall_corner_top_left || !imgs->wall_corner_top_right
		|| !imgs->wall_corner_bottom_left || !imgs->wall_corner_bottom_right
		|| !imgs->wall_horizontal || !imgs->wall_vertical)
	{
		write(2, "Error: Una o más imágenes son NULL\n", 34);
		exit(EXIT_FAILURE);
	}
}
