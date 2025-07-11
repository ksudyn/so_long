/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:45:30 by ksudyn            #+#    #+#             */
/*   Updated: 2025/07/11 16:54:10 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COLLECTABLE "./textures/collectable.xpm"
# define EXIT "./textures/exit.xpm"
# define NOTHING "./textures/nothing.xpm"
# define PLAYER "./textures/player.xpm"
# define WALL "./textures/wall.xpm"
# define WALL_CORNER_TOP_LEFT "./textures/wall_top_left.xpm"
# define WALL_CORNER_TOP_RIGHT "./textures/wall_top_right.xpm"
# define WALL_CORNER_BOTTOM_LEFT "./textures/wall_bottom_left.xpm"
# define WALL_CORNER_BOTTOM_RIGHT "./textures/wall_bottom_right.xpm"
# define WALL_HORIZONTAL "./textures/wall_horizontal.xpm"
# define WALL_VERTICAL "./textures/wall_vertical.xpm"

/*estos numeros se sacan teniendo en cuenta el sistema X11
 *para gestionar la entrada del teclado
 en base a los numeros que representan las teclas*/
# define ESC		65307
# define W		119
# define A		97
# define S		115
# define D		100

# define CELL_SIZE 40//tamaño de cada txtura en píxeles

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_images
{
	void	*wall_img;
	void	*wall_corner_top_left;
	void	*wall_corner_top_right;
	void	*wall_corner_bottom_left;
	void	*wall_corner_bottom_right;
	void	*wall_horizontal;
	void	*wall_vertical;
	void	*nothing_img;
	void	*collectable_img;
	void	*exit_img;
	void	*player_img;
}	t_images;

typedef struct s_game
{
	int				height;
	int				width;
	int				x;
	int				y;
	int				count;
	int				finish;
	void			*mlx;
	void			*win;
	char			**map;
	int				exit_x;
	int				exit_y;
	int				player_count;
	int				exit_count;
	unsigned int	step;
	t_images		images;
}	t_game;

//accesible.c
int		accessible(t_game *game);
//dimension.c
int		dimensions(char *line, char ***map, int *height, t_game *game);
//draw.c
void	draw_tile(t_game *game, char tile, int x, int y);
//flood_fill.c
void	flood_fill(t_game *game, int x, int y, char **map_copy);
void	validade_flood_fill(t_game *game);
//ft_move.c
int		ft_press_key(int keycode, t_game *game);
//ft_utils_mlx.c
void	star_mlx(void **mlx, void **window, int map_width, int map_height);
void	*load_graphics(void *mlx, const char *image_path);
void	draw_image(t_game *game, void *image, int x, int y);
void	ft_free_img(void *mlx, t_images *images);
//ft_utils.c
char	*ft_strcpy(char *s1, char *s2);
int		ft_strcmpr(char *s1, char *s2);
void	ft_write_itoa(unsigned int n);
int		ft_error(char *str);
//main.c
int		main(int argc, char **argv);
//map.c
void	ft_free_map(char **map);
char	**read_map_lines(int fd, t_game *game);
char	**load_map(const char *file, t_game *game);
void	draw_map(t_game *game);
//so_lon.c
void	ft_load_img(void *mlx, t_images *images);
void	ft_reset_data(t_game *game);
//star_close_game.c
void	init_game(t_game *game, char *map_file);
int		close_game(t_game *game);
int		close_game_win(t_game *game);
//textures.c
void	init_player_position(t_game *game);
void	init_exit_position(t_game *game);
void	init_collectable_count(t_game *game);
void	component(t_game *game);
//validate_map.c
void	validate_map(t_game *game);

#endif
