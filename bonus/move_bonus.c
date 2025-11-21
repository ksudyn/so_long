/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:29:02 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:39:10 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_w_bonus(t_game *game)
{
	if (game->y > 0)
	{
		check_enemy_collision(game, game->y - 1, game->x);
		if (game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
		{
			if (game->map[game->y - 1][game->x] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y - 1][game->x] = 'P';
			game->y--;
			game->step++;
			draw_map_bonus(game);
		}
		else if (game->map[game->y - 1][game->x] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win_bonus(game);
		}
	}
}

void	move_s_bonus(t_game *game)
{
	if (game->y < game->height - 1)
	{
		check_enemy_collision(game, game->y + 1, game->x);
		if (game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
		{
			if (game->map[game->y + 1][game->x] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y + 1][game->x] = 'P';
			game->y++;
			game->step++;
			draw_map_bonus(game);
		}
		else if (game->map[game->y + 1][game->x] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win_bonus(game);
		}
	}
}

void	move_d_bonus(t_game *game)
{
	if (game->x < game->width - 1)
	{
		check_enemy_collision(game, game->y, game->x + 1);
		if (game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
		{
			if (game->map[game->y][game->x + 1] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x + 1] = 'P';
			game->x++;
			game->step++;
			draw_map_bonus(game);
		}
		else if (game->map[game->y][game->x + 1] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win_bonus(game);
		}
	}
}

void	move_a_bonus(t_game *game)
{
	if (game->x > 0)
	{
		check_enemy_collision(game, game->y, game->x - 1);
		if (game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'E')
		{
			if (game->map[game->y][game->x - 1] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x - 1] = 'P';
			game->x--;
			game->step++;
			draw_map_bonus(game);
		}
		else if (game->map[game->y][game->x - 1] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win_bonus(game);
		}
	}
}

int	ft_press_key_bonus(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game_bonus(game);
	else if (keycode == W && game->finish == 0)
	{
		game->player_texture = game->images.player_up;
		move_w_bonus(game);
	}
	else if (keycode == S && game->finish == 0)
	{
		game->player_texture = game->images.player_down;
		move_s_bonus(game);
	}
	else if (keycode == D && game->finish == 0)
	{
		game->player_texture = game->images.player_right;
		move_d_bonus(game);
	}
	else if (keycode == A && game->finish == 0)
	{
		game->player_texture = game->images.player_left;
		move_a_bonus(game);
	}
	return (0);
}
