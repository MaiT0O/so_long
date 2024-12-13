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
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct t_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_perso;
	char	*path_perso;
	char	*addr;
	int		x_perso;
	int		y_perso;
	int		width;
	int		height;
}	t_game;

#endif