/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:56:50 by ksudyn            #+#    #+#             */
/*   Updated: 2025/08/07 20:59:15 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    texture_bonus(void  *mlx, t_game  *game)
{
    t_images    *imgs;

    imgs = &game->images;
    imgs->player_up = load_graphics(mlx, "textures/player_up.xpm");
    imgs->player_down = load_graphics(mlx, "textures/player_up.xpm");
    imgs->player_left = load_graphics(mlx, "textures/player_left.xpm");
    imgs->player_right = load_graphics(mlx, "textures/player_right.xpm");

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
}

void	init_game_bonus(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	game->map = load_map(map_file, game);
	if (!game->mlx || !game->map || !game->map[0])
		exit(ft_error("Error: Fallo al iniciar MiniLibX o cargar el mapa.\n"));
	validate_map(game);
	component(game);
	validade_flood_fill(game);
	game->win = mlx_new_window(game->mlx, game->width * CELL_SIZE,
			game->height * CELL_SIZE, "So Long");
	if (!game->win)
		exit(ft_error("Error: Fallo al crear la ventana.\n"));
	ft_load_img(game->mlx, &game->images);
    texture_bonus(game->mlx, game);
}

int	close_game_bonus(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx, &game->images);
    ft_free_img_bonus(game->mlx, &game->images);
	ft_free_map(game->map);
	ft_putstr_fd("Game closed.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_game_win_bonus(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_img(game->mlx, &game->images);
    ft_free_img_bonus(game->mlx, &game->images);
	ft_free_map(game->map);
	ft_putstr_fd("YOU WIN.\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}