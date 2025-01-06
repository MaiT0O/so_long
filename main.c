/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:41:07 by ebansse           #+#    #+#             */
/*   Updated: 2025/01/06 18:05:08 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation(t_game *game, t_map *map, t_img *img, t_data *data)
{
	game->mlx_ptr = mlx_init();
	game->perso_step = 0;

	map->map = tableau_map(map);
	map->spawn = 0;
	map->exit = 0;
	map->item = 0;
	map->valid = 1;
	map->cols = ft_strlen((const char *)map->map[0]);

	img->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm", &img->width, &img->height);
	ft_printf("wall : width = %d   height = %d\n", img->width, img->height);
	img->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm", &img->width, &img->height);
	ft_printf("floor : width = %d   height = %d\n", img->width, img->height);
	img->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/exit.xpm", &img->exit_width, &img->exit_height);
	ft_printf("exit : width = %d   height = %d\n", img->exit_width, img->exit_height);
	img->mine_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/mine.xpm", &img->mine_width, &img->mine_height);
	ft_printf("mine : width = %d   height = %d\n", img->mine_width, img->mine_height);
	img->off_mine_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/off_mine.xpm", &img->off_mine_width, &img->off_mine_height);
	ft_printf("off mine : width = %d   height = %d\n", img->off_mine_width, img->off_mine_height);
	game->perso_img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/perso.xpm", &game->perso_width, &game->perso_height);
	ft_printf("perso : width = %d   height = %d\n", game->perso_width, game->perso_height);

	data->game = game;
    data->map = map;
    data->img = img;
}

/*void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img-> + x * (img->bpp / 8));
	*(int *)dst = color;
}

void	put_image(t_img *dest, t_img *img, int x0, int y0)
{
	int	x;
	int	y;
	int	*img_data;
	int	color;

	img_data = (int *)img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = img_data[y * (img->line_length / 4) + x];
			if ((color >> 24 & 0xFF) == 0)
				put_pixel(dest, x + x0, y + y0, color);
			x++;
		}
		y++;
	}
}*/

int	check_ber(t_map *map, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		map->path_map = str;
		close(fd);
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_game	game;
	t_map	map;
	t_img	img;
	t_data	data;

	if (argc != 2 || !check_ber(&map, argv[1]))
	{
		ft_printf("Veuillez renseignez uniquement l'executable puis une map existante ;)\n");
		return (0);
	}
	else
	{
		initialisation(&game, &map, &img, &data);
		if (map_check(&map, &game, &img))
		{
			game.win_ptr = mlx_new_window(game.mlx_ptr, img.width * (map.cols - 1), img.height * map.line_map, "so_long");
			display_map(&game, &map, &img);
			mlx_key_hook(game.win_ptr, key_press, &data);
			mlx_hook(game.win_ptr, 17, 0, finish, &data);
			mlx_loop(game.mlx_ptr);
		}
	}
	return (1);
}
