/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:45:30 by ksudyn            #+#    #+#             */
/*   Updated: 2024/11/25 20:42:00 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#define COLLECTABLE	"./textures/collectable.xpm"
#define EXIT		"./textures/exit.xpm"
#define NOTHING		"./textures/nothing.xpm"
#define PLAYER		"./textures/player.xpm"
#define WALL		"./textures/wall.xpm"

/*estos numeros se sacan teniendo en cuenta el sistema X11
 *para gestionar la entrada del teclado
 en base a los numeros que representan las teclas*/
#define ESC		65307
#define W		119
#define A		97
#define S		115
#define D		100

#define CELL_SIZE 40//tamaño de cada celda en píxeles

//#define MAP_WIDTH 34//Ancho del mapa
//#define MAP_HEIGHT 6//Alto del mapa

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

//Variables globales, con el exter decimos que
//le estás diciendo al compilador que estas variables existen,
//pero su definición (es decir, donde se les asigna memoria y valores)
//está en algún otro archivo .c
extern void *mlx;
extern void	*collectable_img;
extern void *exit_img;
extern void *nothing_img;
extern void *player_img;
extern void *wall_img;

typedef struct s_game
//Define una estructura para almacenar los datos necesarios del juego
//(MiniLibX, ventana, mapa, etc.)
{
	int		height;
	int		width;
	int		x;
	int		y;
	int		count;
	unsigned int	step;
	int		finish;
	void	*mlx;
	void	*win;
	char	**map;
	int		exit_x;
	int		exit_y;
	int player_count;
    int exit_count;
    int collectable_count;
}	t_game;

//prototitpos.c
//accesible.c
int		accessible(t_game *game);
//dimension.c
int		dimensions(char *line, char ***map, int *height, t_game *game);
//flood_fill.c
void	flood_fill(t_game *game, int x, int y, char **map_copy);
void	validade_flood_fill(t_game *game);
//ft_move.c
int     ft_press_key(int keycode, t_game *game);
//ft_utils_mlx.c
void 	star_mlx(void **mlx, void **window, int map_width, int map_height);
void	*load_graphics(void *mlx, const char *image_path);
void	draw_image(void *mlx, void *window, void *image, int x, int y);
void	ft_free_img(void *mlx);
//ft_utils.c
void	draw_tile(char tile, void *mlx, void *mlx_win, int x, int y);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strcmpr(char *s1, char *s2);
void	ft_write_itoa(unsigned int n);
int		ft_error(char *str);
//main.c
int	main(int argc, char **argv);
//map.c
void	ft_free_map(char **map);
char	**read_map_lines(int fd, t_game *game);
char	**load_map(const char *file, t_game *game);
void	draw_map(t_game *game);
//so_lon.c
void	ft_load_img(void *mlx);
void	ft_reset_data(t_game *game);
//star_close_game.c
void init_game(t_game *game, char *map_file);
int		close_game(t_game *game);
int		close_game_win(t_game *game);
//textures.c
void init_player_position(t_game *game);
void init_exit_position(t_game *game);
void init_collectable_count(t_game *game);
void component(t_game *game);
//validate_map.c
void validate_map(t_game *game);

#endif
