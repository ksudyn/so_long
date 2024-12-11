/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:52:39 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/11 16:10:52 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(char ***map, char **temp, int height)
{
	int	i;

	i = 0;
	if (!(*map))
		return ;
	while (i < height)
	{
		if (!(*map)[i])
		{
			ft_error("Error: mapa corrupto o puntero nulo en copy_map\n");
			exit(1);
		}
		temp[i] = (*map)[i];
		i++;
	}
}

void	handle_map_error(char ***map, char *line)
{
	perror("Error al asignar memoria para el mapa");
	if (*map)
		ft_free_map(*map);
	free(line);
	exit(1);
}

void	initialize_width(char *line, t_game *game)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		game->width = len - 1;
	else
		game->width = len;
}

int	update_map(char ***map, char **temp, char *line, int *height)
{
	copy_map(map, temp, *height);
	if (*map)
		free(*map);
	temp[*height] = line;
	*map = temp;
	(*height)++;
	return (1);
}

int	dimensions(char *line, char ***map, int *height, t_game *game)
{
	char	**temp;

	if (!game->width)
		initialize_width(line, game);
	temp = ft_calloc(*height + 1, sizeof(char *));
	if (!temp)
	{
		handle_map_error(map, line);
		return (0);
	}
	return (update_map(map, temp, line, height));
}
