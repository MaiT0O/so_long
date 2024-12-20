#include "so_long.h"

void	flood_fill(char **map, int x, int y, int rows, int cols)
{
    // Vérifie si la position est hors des limites ou si ce n’est pas un chemin accessible
    if (x < 0 || x >= rows || y < 0 || y >= cols || map[x][y] == '1' || map[x][y] == 'F')
        return;

    // Marque la position comme visitée
    map[x][y] = 'F';

    // Appelle récursivement la fonction pour les 4 directions
    flood_fill(map, x - 1, y, rows, cols); // Haut
    flood_fill(map, x + 1, y, rows, cols); // Bas
    flood_fill(map, x, y - 1, rows, cols); // Gauche
    flood_fill(map, x, y + 1, rows, cols); // Droite
}

int	exit_check(t_map *map)
{
	int	accessible;
	int	i;

	i = -1;
	if (map->exit != 1 || map.spawn != 1)
	{
		ft_printf("La map doit contenir exactement une sortie et un point de spawn");
		return (1);
	}
	map->copy_map = tableau_map(map);
	flood_fill(map->copy_map, map->pos_P[0], map->pos_P[1], map->line_map, map->cols);
	accessible = (map->copy_map[map->pos_E[0]][map->pos_E[1]] == 'F');

	while (++i < map->line_map)
	{
		free(map->copy_map[i]);
	}

	free(map->copy_map);
	return (accessible);
}

int	map_check(t_map *map)
{
	map.spawn = 0;
	map.exit = 0;
	map.item = 0;

	map.map = tableau_map(map);
	if (!rectangle_check(map) || !wall_check(map) || !exit_check(map))
	{
		ft_printf("Error : la map n'est pas conforme.\nPour rappel la map doit suivre précisement ces règles :")
	}
}
