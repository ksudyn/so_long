/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:40:39 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/20 15:31:28 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, char tile, int x, int y)
{
	t_images	*imgs;

	imgs = &game->images;
	if (tile == '1')
		draw_image(game, imgs->wall_img, x, y);
	else if (tile == '0')
		draw_image(game, imgs->nothing_img, x, y);
	else if (tile == 'C')
		draw_image(game, imgs->collectable_img, x, y);
	else if (tile == 'E')
		draw_image(game, imgs->exit_img, x, y);
	else if (tile == 'P')
		draw_image(game, imgs->player_img, x, y);
	if (!imgs->player_img || !imgs->exit_img || !imgs->collectable_img
		|| !imgs->nothing_img || !imgs->wall_img)
	{
		write(2, "Error: Una o más imágenes son NULL\n", 34);
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

	write(1, "STEP: ", 6);
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
