/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:02 by ksudyn            #+#    #+#             */
/*   Updated: 2024/11/25 18:59:51 by ksudyn           ###   ########.fr       */
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
	int	width;
	int	height;
	void	*image;

	if (!mlx || !image_path)
		exit(ft_error("Error: Parámetros inválidos en load_graphics.\n"));
	image = mlx_xpm_file_to_image(mlx, (char *)image_path, &width, &height);
	if (image == NULL)
		exit(ft_error("Error: No se pudo cargar la imagen.\n"));
	return (image);
}

void	draw_image(void *mlx, void *window, void *image, int x, int y)
{
	if (!mlx || !window || !image)
	{
		ft_error("Error: Parámetros inválidos en draw_image.\n");
		return ;
	}
	mlx_put_image_to_window(mlx, window, image, x, y);
}

void	ft_free_img(void *mlx)
{
	if (!mlx)
		return ;
	if (collectable_img)
		mlx_destroy_image(mlx, collectable_img);
	if (exit_img)
		mlx_destroy_image(mlx, exit_img);
	if (nothing_img)
		mlx_destroy_image(mlx, nothing_img);
	if (player_img)
		mlx_destroy_image(mlx, player_img);
	if (wall_img)
		mlx_destroy_image(mlx, wall_img);
}