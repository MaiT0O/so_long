/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:41:07 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/23 16:42:30 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation(t_game *game, t_map *map, t_img *img)
{
	game->perso_path = "assets/perso.xpm";
	game->mlx_ptr = mlx_init();
	game->perso_img = mlx_xpm_file_to_image(game->mlx_ptr, game->perso_path,
	&game->perso_width, &game->perso_height);
	game->perso_x = game->win_width / 2;
	game->perso_y = game->win_height / 2;
	game->perso_step = 0;

	map->map = tableau_map(map);
	map->spawn = 0;
	map->exit = 0;
	map->item = 0;
	map->valid = 0;
	map->cols = ft_strlen((const char *)map->map[0]);

	img->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", &img->width, &img->height);
	ft_printf("width = %d   height = %d\n", img->width, img->height);
	img->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm", &img->width, &img->height);
	ft_printf("width = %d   height = %d\n", img->width, img->height);
	img->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm", &img->exit_width, &img->exit_height);
	ft_printf("width = %d   height = %d\n", img->exit_width, img->exit_height);
	img->mine_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/mine.xpm", &img->mine_width, &img->mine_height);
	ft_printf("width = %d   height = %d\n", img->mine_width, img->mine_height);
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
	t_game game;
	t_map	map;
	t_img	img;

	if (argc != 2 || !check_ber(&map, argv[1]))
	{
		ft_printf("Veuillez renseignez uniquement l'executable puis une map existante ;)\n");
		return (0);
	}
	else
	{
		initialisation(&game, &map, &img);
		if (map_check(&map))
		{
			game.win_ptr = mlx_new_window(game.mlx_ptr, img.width * map.cols, img.height * map.line_map, "so_long");
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.perso_img, game.perso_x, game.perso_y);
			mlx_key_hook(game.win_ptr, key_press, &game);
			clean_map(&map);
			display_2d_array(&map, map.map);
			display_map(&game, &map, &img);
			display_map2(&game, &map, &img);
			mlx_hook(game.win_ptr, 17, 0, close_window, &game);
			mlx_loop(game.mlx_ptr);
		}
	}
	return (1);
}
