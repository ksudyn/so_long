/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/08/11 20:43:18 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	star_mlx(void **mlx, void **window, int map_width, int map_height)
{
	if (!mlx || !window || map_width <= 0 || map_height <= 0)
		exit(ft_error("Error: Parámetros inválidos en star_mlx.\n"));
	*mlx = mlx_init();
	if (*mlx == NULL)
		exit(ft_error("Error: No se pudo inicializar mlx.\n"));
	*window = mlx_new_window(
			*mlx, map_width * CELL_SIZE, map_height * CELL_SIZE, "Mi ventana");
	if (*window == NULL)
	{
		free(*mlx);
		exit(ft_error("Error: No se pudo crear la ventana.\n"));
	}
}

void	*load_graphics(void *mlx, const char *image_path)
{
	int		height;
	int		width;
	void	*image;

	if (!mlx || !image_path)
		exit(ft_error("Error: Parámetros inválidos en load_graphics.\n"));
	image = mlx_xpm_file_to_image(mlx, (char *)image_path, &width, &height);
	if (image == NULL)
		exit(ft_error("Error: No se pudo cargar la imagen.\n"));
	return (image);
}

void	draw_image(t_game *game, void *image, int x, int y)
{
	int	x_pos;
	int	y_pos;

	if (!game->mlx || !game->win || !image)
	{
		ft_error("Error: Parámetros inválidos en draw_image.\n");
		return ;
	}
	x_pos = x * CELL_SIZE;
	y_pos = y * CELL_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, image, x_pos, y_pos);
}

void	ft_free_img(void *mlx, t_images *images)
{
	if (!mlx || !images)
		return ;
	if (images->collectable_img)
		mlx_destroy_image(mlx, images->collectable_img);
	if (images->exit_img)
		mlx_destroy_image(mlx, images->exit_img);
	if (images->nothing_img)
		mlx_destroy_image(mlx, images->nothing_img);
	if (images->player_img)
		mlx_destroy_image(mlx, images->player_img);
	// Liberar imágenes adicionales de muros
	if (images->wall_img)
		mlx_destroy_image(mlx, images->wall_img);
	if (images->wall_corner_top_left)
		mlx_destroy_image(mlx, images->wall_corner_top_left);
	if (images->wall_corner_top_right)
		mlx_destroy_image(mlx, images->wall_corner_top_right);
	if (images->wall_corner_bottom_left)
		mlx_destroy_image(mlx, images->wall_corner_bottom_left);
	if (images->wall_corner_bottom_right)
		mlx_destroy_image(mlx, images->wall_corner_bottom_right);
	if (images->wall_horizontal)
		mlx_destroy_image(mlx, images->wall_horizontal);
	if (images->wall_vertical)
		mlx_destroy_image(mlx, images->wall_vertical);
}
