/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:00:00 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/06 14:23:40 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_item(t_data *data, char c)
{
	if (c == 'C')
	{
		mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, data->img->off_mine_img, data->pos_x * data->img->width, data->pos_y * data->img->height);
		data->map->map[data->pos_y][data->pos_x] = '0';
		data->map->item--;
		return (1);
	}
	return (0);
}

void	render_top(t_data *data)
{
	char	next_case;

	data->pos_x = data->game->perso_x / data->img->width;
	data->pos_y = (data->game->perso_y / data->img->height) - 1;
	next_case = data->map->map[data->pos_y][data->pos_x];
	ft_printf("next_case: %c\n", next_case);
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n", data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			data->game->perso_step++;
			mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, 
				data->img->floor_img, data->game->perso_x, data->game->perso_y);
			data->game->perso_y -= data->img->height;
		}
	}
}

void	render_bottom(t_data *data)
{
	char	next_case;

	data->pos_x = data->game->perso_x / data->img->width;
	data->pos_y = (data->game->perso_y / data->img->height) + 1;
	next_case = data->map->map[data->pos_y][data->pos_x];
	ft_printf("next_case: %c\n", next_case);
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n", data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			data->game->perso_step++;
			mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, 
				data->img->floor_img, data->game->perso_x, data->game->perso_y);
			data->game->perso_y += data->img->height;
		}
	}	
}

void	render_left(t_data *data)
{
	char	next_case;

	data->pos_x = (data->game->perso_x / data->img->width) - 1;
	data->pos_y = data->game->perso_y / data->img->height;
	next_case = data->map->map[data->pos_y][data->pos_x];
	ft_printf("next_case: %c\n", next_case);
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n", data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			data->game->perso_step++;
			mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, 
				data->img->floor_img, data->game->perso_x, data->game->perso_y);
			data->game->perso_x -= data->img->width;
		}
	}
}

void	render_right(t_data *data)
{
	char	next_case;

	data->pos_x = (data->game->perso_x / data->img->width) + 1;
	data->pos_y = data->game->perso_y / data->img->height;
	next_case = data->map->map[data->pos_y][data->pos_x];
	ft_printf("next_case: %c\n", next_case);
	if (next_case != '1' && !chk_item(data, next_case))
	{
		if (next_case == 'E')
		{
			if (data->map->item == 0)
			{
				ft_printf("Felicitation vous avez gagne en : %i coup !\n", data->game->perso_step);
				finish(data);
				return ;
			}
		}
		else
		{
			data->game->perso_step++;
			mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, 
				data->img->floor_img, data->game->perso_x, data->game->perso_y);
			data->game->perso_x += data->img->width;
		}
	}
}
