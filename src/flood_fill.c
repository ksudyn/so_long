/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:16 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/10 15:51:18 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_game *game, int x, int y, char **map_copy)
{
    if (x < 0 || x >= game->width || y < 0 || y >= game->height)
        return;

    if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
        return;

    map_copy[y][x] = 'V';

    flood_fill(game, x + 1, y, map_copy); // Derecha
    flood_fill(game, x - 1, y, map_copy); // Izquierda
    flood_fill(game, x, y + 1, map_copy); // Abajo
    flood_fill(game, x, y - 1, map_copy); // Arriba
}

void validade_flood_fill(t_game *game)
{
    accessible(game);

    // Realizar la validación de accesibilidad
    if (!accessible(game))
    {
        ft_error("Error: mapa no valido\n");
        exit(1);
    }

    ft_putstr_fd("todo es accesible ", 1);

}