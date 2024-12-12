/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:41:07 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/12 17:38:17 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int num, t_game *game)
{
	if (num == 65307)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	return (0);
}

int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (0);
}

int	window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 600, 400, "hi :)");
	if (!game->win_ptr)
		return (free(game->mlx_ptr), 1);
	mlx_loop(game->mlx_ptr);
	mlx_key_hook(game->win_ptr, key_hook, NULL);
	mlx_hook(game->win_ptr, 17, 0, close_window, NULL);
	return (0);
}

int main()
{
	t_game game;

	window(&game);
	return (0);
}
