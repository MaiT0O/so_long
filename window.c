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

void display_2d_array(int rows, char	**array)
{
    int i;

    i = 0;
	while (i < rows)
    {
		ft_printf("%s", array[i]);
		i++;
    }
}

void	flood_fill(t_map *map, int x, int y)
{
    // Vérifie si la position est hors des limites ou si ce n’est pas un chemin accessible
    if (y < 0 || y >= map->line_map || x < 0 || x >= (int)map->cols || 
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
		ft_printf("La map doit contenir exactement une sortie et un point de spawn\n");
		return (0);
	}
	map->copy_map = tableau_map(map);
	flood_fill(map, map->pos_p[1], map->pos_p[0]);
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
	if (!map->map)
		return (0);
	else if (!rectangle_check(map))
	{
		return (0);
	}
	else if (map->spawn == 2 || map->exit == 2 || map->check_item == 0 || map->valid == 1)
	{
		ft_printf("letter\n");
		return (0);
	}
	ft_printf("%d\n", wall_check(map));
	/*else if (!wall_check(map))
	{
		ft_printf("wall\n");
		return (0);
	}*/
	if (!exit_check(map))
	{
		ft_printf("exit\n");
		return (0);
	}
	else
		ft_printf("Map is valid\n");
	return (1);
}
