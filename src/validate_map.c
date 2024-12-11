/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:50:31 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/11 17:03:06 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game == NULL || game->map == NULL || game->map[0] == NULL)
	{
		ft_putstr_fd("Error: Mapa no válido.\n", 1);
		return (0);
	}
	i = 0;
	len = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		if (ft_strlen(game->map[i]) != len)
		{
			ft_putstr_fd("Error: El mapa no es rectangular\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_first_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width -1)
	{
		if (game->map[0][i] != '1')
		{
			ft_error("Error: En los muros (primera fila).\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

int	check_last_row(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width -1)
	{
		if (game->map[game->height - 1][i] != '1')
		{
			ft_error("Error: En los muros (última fila).\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

int	check_side_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
		{
			ft_error("Error: En los muros (columna izquierda).\n");
			exit(EXIT_FAILURE);
		}
		if (game->map[i][game->width - 1] != '1')
		{
			ft_error("Error: En los muros (columna derecha).\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

void	validate_map(t_game *game)
{
	is_rectangular(game);
	check_first_row(game);
	check_last_row(game);
	check_side_walls(game);
}
