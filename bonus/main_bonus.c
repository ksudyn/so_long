/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:56:19 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:31:02 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long_bonus <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	write(1, "Archivo recibido (bonus): ", 27);
	write(1, argv[1], strlen(argv[1]));
	write(1, "\n", 1);
	ft_reset_data(&game);
	init_game_bonus(&game, argv[1]);
	draw_map_bonus(&game);
	mlx_key_hook(game.win, ft_press_key_bonus, &game);
	mlx_hook(game.win, 17, 0, close_game_bonus, &game);
	write(1, "Iniciando loop de MiniLibX (bonus)...\n", 38);
	mlx_loop_hook(game.mlx, enemy_patrol, &game);
	mlx_loop(game.mlx);
	write(1, "Fin del loop de MiniLibX (bonus).\n", 34);
	return (0);
}
