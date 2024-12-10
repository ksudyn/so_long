/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:24:29 by ksudyn            #+#    #+#             */
/*   Updated: 2024/11/25 20:45:13 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**read_map_lines(int fd, t_game *game)
{
	char	*line;
	char	**map;
	int	height;

	map = NULL;
	height = 0;
	while ((line = get_next_line(fd)))
	{
		if (!dimensions(line, &map, &height, game))
			return NULL;
	}
	game->height = height;
	return map;
}

char **load_map(const char *file, t_game *game)
{
	int fd;

	fd = open(file, O_RDONLY); 
	if (fd == -1)
		return (perror("Error al abrir el archivo"), NULL);

	char **map = read_map_lines(fd, game);
	close(fd);

	if (!map)
		ft_putstr_fd("Error: el mapa está vacío o inválido\n", 2);
	return map;
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->win);
	
	y = 0;
	
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game->map[y][x], game->mlx, game->win, x, y);
			x++;
		}
		y++;
	}
}
