/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:25:24 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/23 15:29:14 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
    // Vérifie si la position est hors des limites ou si ce n’est pas un chemin accessible
    if (y < 0 || y >= map->line_map || x < 0 || x >= map->cols || 
	map->copy_map[y][x] == '1' || map->copy_map[y][x] == 'F')
        return;

    // Marque la position comme visitée
    map->copy_map[y][x] = 'F';

    // Appelle récursivement la fonction pour les 4 directions
    flood_fill(map, x - 1, y); // Haut
    flood_fill(map, x + 1, y); // Bas
    flood_fill(map, x, y - 1); // Gauche
    flood_fill(map, x, y + 1); // Droite
}

int	exit_check(t_map *map)
{
	int	accessible;
	int	i;

	i = -1;
	if (map->exit != 1 || map->spawn != 1)
	{
		ft_printf("La map doit contenir exactement une sortie et un point de spawn");
		return (1);
	}
	map->copy_map = tableau_map(map);
	flood_fill(map->copy_map, map->pos_p[1], map->pos_p[0]);
	accessible = (map->copy_map[map->pos_e[1]][map->pos_e[0]] == 'F');

	while (++i < map->line_map)
	{
		free(map->copy_map[i]);
	}

	free(map->copy_map);
	return (accessible);
}

int	map_check(t_map *map)
{
	map->spawn = 0;
	map->exit = 0;
	map->item = 0;
	map->valid = 0;

	map->map = tableau_map(map);
	if (!rectangle_check(map) || !wall_check(map) || !exit_check(map) || map->spawn == 2 || map->exit == 2 || map->check_item <= 0 || map->valid == 1)
	{
		ft_printf("Error : la map n'est pas conforme. La map doit respecter les regles indique sur le sujet");
		return (1);
	}
}

