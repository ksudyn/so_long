/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_close_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:08:46 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:39:25 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_game_bonus(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	game->map = load_map(map_file, game);
	if (!game->mlx || !game->map || !game->map[0])
		exit(ft_error("Error: Fallo al iniciar MiniLibX o cargar el mapa.\n"));
	validate_map(game);
	component(game);
	validade_flood_fill(game);
	game->win = mlx_new_window(game->mlx, game->width * CELL_SIZE, game->height
			* CELL_SIZE, "So Long");
	if (!game->win)
		exit(ft_error("Error: Fallo al crear la ventana.\n"));
	ft_load_img(game->mlx, &game->images);
	texture_bonus(game->mlx, game);
}

int	close_game_bonus(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx, &game->images);
	ft_free_img_bonus(game->mlx, &game->images);
	ft_free_map(game->map);
	ft_putstr_fd("Game closed.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_game_win_bonus(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx, &game->images);
	ft_free_img_bonus(game->mlx, &game->images);
	ft_free_map(game->map);
	ft_putstr_fd("YOU WIN.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
