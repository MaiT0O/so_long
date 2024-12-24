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
	int		perso_heigth;
	int		perso_x;
	int		perso_y;
	void	*perso_img;
	char	*perso_path;
	int		perso_step;
}	t_game;

typedef struct t_map
{
	char	*path_map;
	char	**map;
	char	**copy_map;
	int		fd;
	int		check;
	int		spawn;
	int		exit;
	int		item;
	int		valid;
	int		line_map;
	size_t	cols;
	int		pos_e[2];
	int		pos_p[2];
	int		check_wall;
	int		check_item;
	int		check_rectangle;
}	t_map;

typedef struct t_img
{
	void	*wall_img;
	char	*wall_path;
	int		wall_width;
	int		wall_heigth;
	void	*floor_img;
	char	*flor_path;
	int		floor_width;
	int		floor_heigth;
	void	*mine_img;
	char	*mine_path;
	int		mine_width;
	int		mine_heigth;
	void	*exit_img;
	char	*exit_path;
	int		exit_width;
	int		exit_heigth;
}	t_img;

void	display_character(t_game *game);
int		move(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);
char	**remplir_tableau(char **map, int fd);
char	**tableau_map(t_map *map);
int		wall_check(t_map *map);
void	letter_number_check(t_map *map, char c, int y, int x);
int		rectangle_check(t_map *map);
void	flood_fill(t_map *map, int x, int y);
int		exit_check(t_map *map);
int		map_check(t_map *map);

#endif