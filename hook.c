/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:59:46 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/23 15:40:42 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_character(t_game *game)
{
	game->perso_pas++;
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso_img,
	game->perso_x, game->perso_y);
	ft_printf("%i\n", game->perso_pas);
	
}

int	move(int keycode, t_game *game)
{
	game->perso_pas = 0;
	
	if (keycode == 122)	// Z
	{
		game->perso_y -= 10;
		display_character(game);
	}
	else if (keycode == 115 )// S
	{
		game->perso_y += 10;
		display_character(game);
	}
	else if (keycode == 113)// Q
	{
		game->perso_x-= 10;
		display_character(game);
	}
	else if (keycode == 100)// D
	{
		game->perso_x += 10;
		display_character(game);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	move(keycode, game);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}