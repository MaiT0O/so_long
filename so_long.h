/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:21:26 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/23 16:30:28 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct t_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		perso_width;
	int		perso_height;
	void	*perso_img;
	int		perso_step;
	int		perso_x;
	int		perso_y;
	int		collect;
}	t_game;

typedef struct t_map
{
	char	*path_map;
	char	**map;
	char	**copy_map;
	int		fd;
	int		spawn;
	int		exit;
	int		item;
	int		valid;
	int		line_map;
	size_t	cols;
	int		pos_e[2];
	int		pos_p[2];
}	t_map;

typedef struct t_img
{
	int		height;
	int		width;
	void	*finish_img;
	int		finish_width;
	int		finish_height;
	void	*wall_img;
	void	*floor_img;
	void	*mine_img;
	int		mine_width;
	int		mine_height;
	void	*off_mine_img;
	int		off_mine_width;
	int		off_mine_height;
	void	*exit_img;
	int		exit_width;
	int		exit_height;
}	t_img;

typedef struct t_data
{
	int		pos_x;
	int		pos_y;
	t_game	*game;
	t_map	*map;
	t_img	*img;
}	t_data;

void	display_character(t_data *data);
void	display_2d_array(t_map *map, char	**array);
int		move(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);
int		close_window(t_game *game);
char	**remplir_tableau(char **map, int fd);
char	**tableau_map(t_map *map);
int		wall_check(t_map *map);
void	letter_number_check(t_map *map, int i, int j);
int		rectangle_check(t_map *map);
void	flood_fill(t_map *map, int x, int y);
int		exit_check(t_map *map);
int		map_check(t_map *map, t_game *game, t_img *img);
void	display_map(t_game *game, t_map *map, t_img *img);
int		chk_item(t_data *data, char c);
void	render_top(t_data *data);
void	render_bottom(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	finish(t_data *data);

#endif