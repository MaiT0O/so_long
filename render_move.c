/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:00:00 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/13 18:33:23 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_item(t_data *data, char c)
{
	if (c == 'C')
	{
		put_image(data->map->img_map, data->map->sprites_array[1],
			data->pos_x * data->game->width, data->pos_y * data->game->height);
		put_image(data->map->img_map, data->map->sprites_array[3],
			data->pos_x * data->game->width, data->pos_y * data->game->height);
		display_map(data->game, data->map);
		data->map->map[data->pos_y][data->pos_x] = 'N';
		data->map->item--;
		return (1);
	}
	else if (c == 'N')
	{
		put_image(data->map->img_map, data->map->sprites_array[1],
			data->pos_x * data->game->width, data->pos_y * data->game->height);
		display_map(data->game, data->map);
		return (0);
	}
	return (0);
}

void	render_top(t_data *data)
{
	char	next_case;

	data->pos_x = data->game->perso_x / data->game->width;
	data->pos_y = (data->game->perso_y / data->game->height) - 1;
	next_case = data->map->map[data->pos_y][data->pos_x];
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n",
					data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			put_floor(data);
			data->game->perso_y -= data->game->height;
			display_map(data->game, data->map);
		}
	}
}

void	render_bottom(t_data *data)
{
	char	next_case;

	data->pos_x = data->game->perso_x / data->game->width;
	data->pos_y = (data->game->perso_y / data->game->height) + 1;
	next_case = data->map->map[data->pos_y][data->pos_x];
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n",
					data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			put_floor(data);
			data->game->perso_y += data->game->height;
			display_map(data->game, data->map);
		}
	}
}

void	render_left(t_data *data)
{
	char	next_case;

	data->pos_x = (data->game->perso_x / data->game->width) - 1;
	data->pos_y = data->game->perso_y / data->game->height;
	next_case = data->map->map[data->pos_y][data->pos_x];
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n",
					data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			put_floor(data);
			data->game->perso_x -= data->game->width;
			display_map(data->game, data->map);
		}
	}
}

void	render_right(t_data *data)
{
	char	next_case;

	data->pos_x = (data->game->perso_x / data->game->width) + 1;
	data->pos_y = data->game->perso_y / data->game->height;
	next_case = data->map->map[data->pos_y][data->pos_x];
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n",
					data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			put_floor(data);
			data->game->perso_x += data->game->width;
			display_map(data->game, data->map);
		}
	}
}
