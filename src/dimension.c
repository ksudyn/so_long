/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:52:39 by ksudyn            #+#    #+#             */
/*   Updated: 2024/12/09 16:52:58 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    copy_map(char ***map, char **temp, int height)
{
    int i;

    i = 0;
    if (!(*map))
    return;

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

void handle_map_error(char ***map, char *line)
{
    perror("Error al asignar memoria para el mapa");

    if (*map)
        ft_free_map(*map);
    
    free(line);
    exit(1);
}

int dimensions(char *line, char ***map, int *height, t_game *game)
{
    if (!game->width)
    {
        game->width = ft_strlen(line) - 
                    (line[ft_strlen(line) - 1] == '\n' ? 1 : 0);
    }

    char **temp = ft_calloc(*height + 1, sizeof(char *));
    if (!temp)
    {
        handle_map_error(map, line);
        return 0;
    }

    copy_map(map, temp, *height);

    if (*map)
        free(*map);
    
    temp[*height] = line;
    *map = temp;
    (*height)++;

    return 1;
}


