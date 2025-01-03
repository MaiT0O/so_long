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

void	finish(t_data *data)
{
	int		i;

	i = 0;
	if (data->map->map != NULL)
	{
		while (data->map->map[i] != NULL)
		{
			free(data->map->map[i]);
			i++;
		}
		free(data->map->map);
		mlx_destroy_image(data->game->mlx_ptr, data->img->wall_img);
		mlx_destroy_image(data->game->mlx_ptr, data->img->floor_img);
		mlx_destroy_image(data->game->mlx_ptr, data->img->mine_img);
		mlx_destroy_image(data->game->mlx_ptr, data->img->off_mine_img);
		mlx_destroy_image(data->game->mlx_ptr, data->img->exit_img);
		mlx_destroy_image(data->game->mlx_ptr, data->game->perso_img);
	}
	mlx_destroy_display(data->game->mlx_ptr);
	free(data->game->mlx_ptr);
	exit(0);
}

void display_2d_array(t_map *map, char	**array)
{
    int i;

    i = 0;
	while (i < map->line_map)
    {
		ft_printf("%s", array[i]);
		i++;
    }
}

void	flood_fill(t_map *map, int y, int x)
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
		return (0);
	map->copy_map = tableau_map(map);
	if (map->copy_map != NULL)
	{
		flood_fill(map, map->pos_p[0], map->pos_p[1]);
		if (map->pos_e[1] < (int)map->cols && map->pos_e[0] < map->line_map)
			accessible = (map->copy_map[map->pos_e[0]][map->pos_e[1]] == 'F');
		else
			accessible = 0; // Si les indices sont hors limites, considérez comme non accessible
		i = -1;
		while (++i < map->line_map)
		{
			free(map->copy_map[i]);
		}
		free(map->copy_map);
		map->copy_map = NULL; // Évitez les doubles free
	}
	else
		accessible = 0; // Si copy_map est NULL, considérez comme non accessible
	return (accessible);
}

int	map_check(t_map *map, t_game *game, t_img *img)
{
	letter_number_check(map, 0, 0);
	if (!map->map)
		return (0);
	else if (!rectangle_check(map) || map->spawn == 2 || map->exit == 2 
	|| map->item == 0 || map->valid == 1 || !wall_check(map) 
	|| !exit_check(map))
		ft_printf("La map doit respecter les regles de l'énoncé\n");
	else
	{
		ft_printf("Map is valid\n");
		game->perso_x = map->pos_p[1] * img->width;
		game->perso_y = map->pos_p[0] * img->height;
		return (1);
	}
	return (0);
}
