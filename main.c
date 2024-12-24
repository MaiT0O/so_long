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

/*int	display_map(t_game *game, t_map *map, t_img *img)
{
	img->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", &img->wall_width, &img->wall_heigth);
	img->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm", &img->floor_width, &img->floor_heigth);
	img->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm", &img->exit_width, &img->exit_heigth);
	img->mine_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/mine.xpm", &img->mine_width, &img->mine_heigth);
}*/

void	initialisation(t_game *game)
{
	game->perso_path = "assets/perso.xpm";
	game->mlx_ptr = mlx_init();
	game->win_width = 800;
	game->win_height = 600;
	game->perso_img = mlx_xpm_file_to_image(game->mlx_ptr, game->perso_path,
	&game->perso_width, &game->perso_heigth);
	game->perso_x = game->win_width / 2;
	game->perso_y = game->win_height / 2;
	game->perso_step = 0;
}

int	check_ber(t_map *map, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	ft_printf("%d\n", fd);
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

	if (argc != 2 || !check_ber(&map, argv[1]))
	{
		ft_printf("Veuillez renseignez uniquement l'executable puis une map existante ;)\n");
		return (1);
	}
	else
	{
		initialisation(&game);
		if (!map_check(&map))
			return (0);
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.win_width, game.win_height, "so_long");
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.perso_img, game.perso_x, game.perso_y);
		map.path_map = argv[1];
		mlx_key_hook(game.win_ptr, key_press, &game);
		mlx_hook(game.win_ptr, 17, 0, close_window, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (1);
}
