/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:39:43 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/11 15:29:08 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	if (game->y > 0)
	{
		if (game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
		{
			if (game->map[game->y - 1][game->x] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y - 1][game->x] = 'P';
			game->y--;
			game->step++;
			ft_write_itoa(game->step);
			draw_map(game);
		}
		else if (game->map[game->y - 1][game->x] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win(game);
		}
	}
}

void	move_s(t_game *game)
{
	if (game->y < game->height - 1)
	{
		if (game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
		{
			if (game->map[game->y + 1][game->x] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y + 1][game->x] = 'P';
			game->y++;
			game->step++;
			ft_write_itoa(game->step);
			draw_map(game);
		}
		else if (game->map[game->y + 1][game->x] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win(game);
		}
	}
}

void	move_d(t_game *game)
{
	if (game->x < game->width - 1)
	{
		if (game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
		{
			if (game->map[game->y][game->x + 1] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x + 1] = 'P';
			game->x++;
			game->step++;
			ft_write_itoa(game->step);
			draw_map(game);
		}
		else if (game->map[game->y][game->x + 1] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win(game);
		}
	}
}

void	move_a(t_game *game)
{
	if (game->x > 0)
	{
		if (game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'E')
		{
			if (game->map[game->y][game->x - 1] == 'C')
				game->count--;
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x - 1] = 'P';
			game->x--;
			game->step++;
			ft_write_itoa(game->step);
			draw_map(game);
		}
		else if (game->map[game->y][game->x - 1] == 'E'
		&& game->count == 0)
		{
			game->finish = 1;
			close_game_win(game);
		}
	}
}

int	ft_press_key(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W && game->finish == 0)
		move_w(game);
	else if (keycode == S && game->finish == 0)
		move_s(game);
	else if (keycode == D && game->finish == 0)
		move_d(game);
	else if (keycode == A && game->finish == 0)
		move_a(game);
	return (0);
}
