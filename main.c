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


int	display(t_game	*game)
{
	game->perso_path = "assets/perso.xpm";

	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1000, 500, "jeu");
	game->perso_img = mlx_xpm_file_to_image(game->mlx_ptr, game->perso_path,
	&game->perso_width, &game->perso_heigth);
	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso_img, 200, 200);
	
	game->perso_x = 200;
	game->perso_y = 200;

	mlx_key_hook(game->win_ptr, key_press, &game);
	mlx_hook(game->win_ptr, 17, 0, close_window, &game);
	
	mlx_loop(game->mlx_ptr);
	return (0);
}

/*int	display_map(t_game *game, t_map *map, t_img *img)
{
	img->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", &img->wall_width, &img->wall_heigth);
	img->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm", &img->floor_width, &img->floor_heigth);
	img->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm", &img->exit_width, &img->exit_heigth);
	img->mine_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/mine.xpm", &img->mine_width, &img->mine_heigth);
}*/	

int	main(int argc, char	**argv)
{
	t_game	*game;
	t_map	*map;
	//t_img	*img;
	
	map = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
    if (!map || !game)
        return (1);
	
	else if (argc != 2)
	{
		ft_printf("Veuillez renseignez uniquement l'executable puis la map ;)");
		return (0);
	}
	else
	{
		map->path_map = argv[1];
		tableau_map(map);
		map_check(map);
		display(game);
	}
	return (0);
}
