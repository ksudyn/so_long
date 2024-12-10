/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:37:55 by ksudyn            #+#    #+#             */
/*   Updated: 2024/11/25 20:38:03 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	write(1, "Archivo recibido: ", 18);
	write(1, argv[1], strlen(argv[1]));
	write(1, "\n", 1);
	
	ft_reset_data(&game);
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_key_hook(game.win, ft_press_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	write(1, "Iniciando loop de MiniLibX...\n", 28);
	mlx_loop(game.mlx);
	write(1, "Fin del loop de MiniLibX.\n", 25);
	return (0);
}
