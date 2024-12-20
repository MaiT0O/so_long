/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:41:07 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/13 17:15:12 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display(t_game	*game, t_perso	*perso)
{
	perso.path = "assets/perso.xpm";

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1000, 500, "jeu");
	perso.img = mlx_xpm_file_to_image(game.mlx_ptr, perso.path, &perso.width, &perso.height);
	
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, perso.img, 200, 200);
	
	perso.x = 200;
	perso.y = 200;

	mlx_key_hook(game.win_ptr, key_press, &game, &perso);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	
	mlx_loop(game.mlx_ptr);
	return (0);
}

int	main(int argc, char	**argv)
{
	t_game	game;
	t_perso	perso;
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Veuillez renseignez uniquement l'executable puis la map ;)");
		return (0);
	}
	else
	{
		map.path_map = argv[1];
		tableau_map(&map);
		display(&game, &perso);
	}
	return (0);
}
