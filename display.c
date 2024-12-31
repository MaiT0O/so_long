#include "so_long.h"

void	display_map(t_game *game, t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line_map)
	{
		j = 0;
		while (j < (int)map->cols && map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->wall_img, i * img->width, j * img->height);
			else if (map->map[i][j] == '0' || map->map[i][j] == 'E' || map->map[i][j] == 'C' || map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->floor_img, i * img->width, j * img->height);			
			j++;
		}
		i++;
	}
}

void	display_map2(t_game *game, t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line_map)
	{
		j = 0;
		while (j < (int)map->cols && map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->exit_img, i * img->width, j * img->height);
			if (map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->mine_img, i * img->width, j * img->height);
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso_img, i * img->width, j * img->height);
			j++;
		}
		i++;
	}
}
