/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:44:00 by ksudyn            #+#    #+#             */
/*   Updated: 2025/11/21 16:33:30 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h" // 👈 Importas todo lo común: structs, constantes, etc.

// Aquí solo defines lo que es exclusivo del bonus
// Versión bonus de las funciones de movimiento
void	move_w_bonus(t_game *game);
void	move_a_bonus(t_game *game);
void	move_s_bonus(t_game *game);
void	move_d_bonus(t_game *game);
int		ft_press_key_bonus(int keycode, t_game *game);
// Versión bonus del dibujado
void	draw_map_bonus(t_game *game);

void	init_game_bonus(t_game *game, char *map_file);
void	texture_bonus(void *mlx, t_game *game);
int		close_game_win_bonus(t_game *game);
int		close_game_bonus(t_game *game);
void	ft_free_img_bonus(void *mlx, t_images *images);
void	check_enemy_collision(t_game *game, int next_y, int next_x);
// Otras funciones específicas del bonus si agregas enemigos, animaciones...

void	move_enemy(t_game *game, int y, int x);
int		enemy_patrol(t_game *game);
int		dead(t_game *game);

#endif
