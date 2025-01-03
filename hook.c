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

void	display_map(t_game *game, t_map *map, t_img *img)
{
    int	i;
    int	j;

    i = 0;
    while (i < map->line_map)
    {
        j = 0;
        while (j < (int)map->cols)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->floor_img, j * img->width, i * img->height);
            // Dessiner les autres éléments par-dessus
            if (map->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->wall_img, j * img->width, i * img->height);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->exit_img, j * img->width, i * img->height);
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->mine_img, j * img->width, i * img->height);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->perso_img, game->perso_x, game->perso_y);
}

void	display_character(t_data *data)
{
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, data->img->floor_img, data->game->perso_x, data->game->perso_y);
	data->game->perso_step++;
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, data->game->perso_img, data->game->perso_x, data->game->perso_y);
	ft_printf("Steps: %i\n", data->game->perso_step);
}

int	move(int keycode, t_data *data)
{
    if (!data || !data->game)
        return (0);

    else if ((keycode == 122 || keycode == 65362)) // Z (Haut)
    {
        render_top(data);
		display_character(data);
    }
    else if ((keycode == 115 || keycode == 65364)) // S (Bas)
    {
        render_bottom(data);
		display_character(data);
    }
    else if ((keycode == 113 || keycode == 65361)) // Q (Gauche)
    {
        render_left(data);
		display_character(data);
    }
    else if ((keycode == 100 || keycode == 65363)) // D (Droite)
    {
        render_right(data);
		display_character(data);
    }
    return (1);
}

int	close_window(t_game *game)
{
	if (!game)
		exit(0);

	if (game->mlx_ptr && game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
	return (1);
}
int	key_press(int keycode, t_data *data)
{
    if (!data)
        return (0);

    if (keycode == 65307) // Échappement
        close_window(data->game);
    else
        move(keycode, data);
    return (1);
}

