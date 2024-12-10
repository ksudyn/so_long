/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:40:39 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/02 14:40:44 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(char tile, void *mlx, void *mlx_win, int x, int y)
{
	if (tile == '1')
		draw_image(mlx, mlx_win, wall_img, x * CELL_SIZE, y * CELL_SIZE);
	else if (tile == '0')
		draw_image(mlx, mlx_win, nothing_img, x * CELL_SIZE, y * CELL_SIZE);
	else if (tile == 'C')
		draw_image(mlx, mlx_win, collectable_img, x * CELL_SIZE, y * CELL_SIZE);
	else if (tile == 'E')
		draw_image(mlx, mlx_win, exit_img, x * CELL_SIZE, y * CELL_SIZE);
	else if (tile == 'P')
        draw_image(mlx, mlx_win, player_img, x * CELL_SIZE, y * CELL_SIZE);
	
	if (!player_img || !exit_img || !collectable_img || !nothing_img || !wall_img)
        {
            write(2, "Error: _img es NULL\n", 20);
            exit(EXIT_FAILURE);
        }
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_strcmpr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_write_itoa(unsigned int n)
{
	char	*str;

	write(1, "STEP_: ", 7);
	str = ft_itoa(n);
	if (str)
	{
		write(1, str, ft_strlen(str));
		free(str);
	}
	write(1, "\n", 1);
}

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
}
