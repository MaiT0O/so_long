/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:41:07 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/14 16:44:36 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_values(t_map *map)
{
	map->spawn = 0;
	map->exit = 0;
	map->item = 0;
	map->valid = 1;
	map->cols = ft_strlen((const char *)map->map[0]);
}

void	initialisation(t_game *game, t_map *map, t_img *img, t_data *data)
{
	game->mlx_ptr = mlx_init();
	game->perso_step = 0;
	map->map = tableau_map(map);
	init_map_values(map);
	map->sprites_array = load_sprites(game, "./assets/", 6);
	game->perso_height = map->sprites_array[4]->height;
	game->perso_width = map->sprites_array[4]->width;
	game->off_height = map->sprites_array[3]->height;
	game->off_width = map->sprites_array[3]->width;
	game->height = map->sprites_array[1]->height;
	game->width = map->sprites_array[1]->width;
	game->win_w = game->width * (map->cols - 1);
	game->win_h = game->height * map->line_map;
	data->game = game;
	data->map = map;
	data->img = img;
}

int	key_press(int keycode, t_data *data)
{
	if (!data)
		return (0);
	if (keycode == 65307)
		finish(data);
	else
		move(keycode, data);
	return (1);
}

int	check_ber(t_map *map, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		map->path_map = str;
		close(fd);
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_game	game;
	t_map	map;
	t_img	img;
	t_data	data;

	if (argc != 2 || !check_ber(&map, argv[1]))
	{
		ft_printf("Veuillez renseignez une map existante ;)\n");
		return (0);
	}
	else
	{
		initialisation(&game, &map, &img, &data);
		if (map_check(&map, &game))
		{
			game.win_ptr = mlx_new_window(game.mlx_ptr,
					game.win_w, game.win_h, "so_long");
			map.img_map = new_image(game.mlx_ptr, game.win_w, game.win_h);
			create_map(&game, &map);
			mlx_key_hook(game.win_ptr, key_press, &data);
			mlx_hook(game.win_ptr, 17, 0, finish, &data);
			mlx_loop(game.mlx_ptr);
		}
	}
	return (1);
}
