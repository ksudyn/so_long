/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:56:50 by ksudyn            #+#    #+#             */
/*   Updated: 2025/08/11 17:53:07 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    texture_bonus(void  *mlx, t_game  *game)
{
    t_images    *imgs;

    imgs = &game->images;
    imgs->player_up = load_graphics(mlx, "textures/player_up.xpm");
    imgs->player_down = load_graphics(mlx, "textures/player_down.xpm");
    imgs->player_left = load_graphics(mlx, "textures/player_left.xpm");
    imgs->player_right = load_graphics(mlx, "textures/player_right.xpm");
    imgs->enemy_img = load_graphics(mlx, "textures/enemy.xpm");

    if(!imgs->player_up || !imgs->player_down || !imgs->player_left ||
        !imgs->player_right)
    {
        write(2, "Error: No se pudieron cargar las texturas del player\n", 54);
        exit(EXIT_FAILURE);
    }
    game->player_texture = imgs->player_down;
}

void ft_free_img_bonus(void *mlx, t_images *images)
{
    if(images->player_up)
        mlx_destroy_image(mlx, images->player_up);
    if(images->player_down)
        mlx_destroy_image(mlx, images->player_down);
    if(images->player_left)
        mlx_destroy_image(mlx, images->player_left);
    if(images->player_right)
        mlx_destroy_image(mlx, images->player_right);
    if (images->enemy_img)
    	mlx_destroy_image(mlx, images->enemy_img);

}
