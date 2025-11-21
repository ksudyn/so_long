/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:20:49 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:41:18 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_enemy(t_game *game, int y, int x)
{
	int	dir;
	int	new_y;
	int	new_x;

	dir = rand() % 4;
	new_y = y;
	new_x = x;
	if (dir == 0)
		new_y--;
	else if (dir == 1)
		new_y++;
	else if (dir == 2)
		new_x--;
	else if (dir == 3)
		new_x++;
	if (new_y < 0 || new_y >= game->height || new_x < 0
		|| new_x >= game->width)
		return ;
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E'
		|| game->map[new_y][new_x] == 'C')
		return ;
	if (game->map[new_y][new_x] == 'P')
		dead(game);
	game->map[y][x] = '0';
	game->map[new_y][new_x] = 'X';
}

/* Moves all enemies periodically */
int	enemy_patrol(t_game *game)
{
	static int	frame;
	int			y;
	int			x;

	frame++;
	/* Adjust speed: higher = slower enemy */
	if (frame < 20000)
		return (0);
	frame = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'X')
				move_enemy(game, y, x);
			x++;
		}
		y++;
	}
	draw_map_bonus(game);
	return (0);
}
