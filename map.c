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
#include <stdio.h>

void    display_character(t_game *game)
{
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_perso, game->x_perso, game->y_perso);
}
int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);	
	}	
	else if (keycode == 65362)
	{
		game->y_perso += 10;
		display_character(game);
	}
	else if (keycode == 65364)
	{
		game->y_perso -= 10;
		display_character(game);
	}
	else if (keycode == 65361)
	{
		game->x_perso -= 10;
		display_character(game);
	}
	else if (keycode == 65363)
	{
		game->y_perso += 10;
		display_character(game);
	}
	return (0);
}


int	main(void)
{
	t_game	game;

	game.path_perso = "assets/persoo.xpm";

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 1920, 1080, "coucou");
	game.img_perso = mlx_xpm_file_to_image(game.mlx_ptr, game.path_perso, &game.width, &game.height);
	
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_perso, 200, 200);
	
	mlx_key_hook(game.win_ptr, key_press, &game);
	
	mlx_loop(game.mlx_ptr);
}
