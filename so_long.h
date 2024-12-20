/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:32:23 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/13 16:25:35 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# ifndef ERROR_MSG
#  define ERROR_MSG "Error : la map n'est pas conforme.\nPour rappel la map doit suivre précisement ces règles :\n\t "
# endif

typedef struct t_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		heigth;
}	t_game;

typedef struct t_map
{
	char	*path_map;
	char	**map;
	char	**copy_map;
	int		spawn;
	int		exit;
	int		item;
	int		valid;
	int		line_map;
	size_t	cols;
	int		pos_E[2];
	int		pos_P[2];
	int		check_wall;
	int		check_item;
	int		check_rectangle;
}	t_map;

typedef struct t_perso
{
	int		width;
	int		heigth;
	int		x;
	int		y;
	void	*img;
	char	*path;
}	t_perso;

typedef struct t_img
{
	int		width;
	int		heigth;
}	t_img;

void	display_character(t_game *game);
int		move(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
int		close_window(t_game *game);
void	remplir_tableau(t_map *map, int fd);
void	tableau_map(t_map *map);
int		wall_check(t_map *map);
void	letter_number_check(t_map *map, char c);
int		rectangle_check(t_map *map);

#endif