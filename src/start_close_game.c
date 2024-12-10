/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_close_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:30:20 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/05 20:33:58 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game, char *map_file)
{
    if (!(game->mlx = mlx_init()) || !(game->map = load_map(map_file, game)) 
        || !game->map[0])
        exit(ft_error("Error: Fallo al iniciar MiniLibX o cargar el mapa.\n"));
    
    component(game);
    validade_flood_fill(game);
    
    if (!(game->win = mlx_new_window(game->mlx, game->width * CELL_SIZE, 
        game->height * CELL_SIZE, "So Long")))
        exit(ft_error("Error: Fallo al crear la ventana.\n"));
    
    ft_load_img(game->mlx);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx);
	ft_free_map(game->map);
	ft_putstr_fd("Game closed.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_game_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx);
	ft_free_map(game->map);
	ft_putstr_fd("YOU WIN.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
