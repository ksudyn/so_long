/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:02:18 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:38:49 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	dead(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx, &game->images);
	ft_free_img_bonus(game->mlx, &game->images);
	ft_free_map(game->map);
	ft_putstr_fd("YOU DEAD.\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}

void	check_enemy_collision(t_game *game, int next_y, int next_x)
{
	if (game->map[next_y][next_x] == 'X')
	{
		ft_putstr_fd("You were caught by an enemy!\n", 1);
		dead(game);
	}
}
