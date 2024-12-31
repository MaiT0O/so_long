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

void	display_character(t_game *game)
{
	if (!game || !game->mlx_ptr || !game->win_ptr || !game->perso_img)
		return;

	game->perso_step++;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso_img,
							game->perso_x, game->perso_y);
	ft_printf("Steps: %i\n", game->perso_step);
}

int	move(int keycode, t_game *game)
{
	if (!game)
		return (0);

	if ((keycode == 122 || keycode == 65362) && game->perso_y > 0) // Z (Haut)
	{
		game->perso_y -= 10;
		display_character(game);
	}
	else if ((keycode == 115 || keycode == 65364) && game->perso_y < game->win_height - 10) // S (Bas)
	{
		game->perso_y += 10;
		display_character(game);
	}
	else if ((keycode == 113 || keycode == 65361) && game->perso_x > 0) // Q (Gauche)
	{
		game->perso_x -= 10;
		display_character(game);
	}
	else if ((keycode == 100 || keycode == 65363) && game->perso_x < game->win_width - 10) // D (Droite)
	{
		game->perso_x += 10;
		display_character(game);
	}
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	if (!game)
		return (0);

	if (keycode == 65307) // Échappement
		close_window(game);
	else
		move(keycode, game);
	return (1);
}

int	close_window(t_game *game)
{
	if (!game)
		exit(0);

	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
	return (1);
}

void	clean_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (map->map)
	{
		while (i < map->line_map)
		{
			j = 0;
			while (j < (int)map->cols)
			{
				if (map->map[i][j] == '\n')
				{
					map->map[i][j] = '\0';
					break;
				}
				j++;
			}
			i++;
		}
	}
}
