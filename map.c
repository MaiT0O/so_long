/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebansse <ebansse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:09:44 by ebansse           #+#    #+#             */
/*   Updated: 2024/12/23 16:44:53 by ebansse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**remplir_tableau(char **map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**tableau_map(t_map *map)
{
	char	*line;
	char	**mapp;
	int		fd;

	fd = open(map->path_map, O_RDONLY);
	line = get_next_line(fd);
	map->line_map = 0;
	while (line != NULL)
	{
		map->line_map++;
		line = get_next_line(fd);
	}
	close(fd);
	mapp = (char **)malloc((map->line_map + 1) * sizeof(char *));
	if (!mapp)
		return (NULL);
	fd = open(map->path_map, O_RDONLY);
	mapp = remplir_tableau(mapp, fd);
	close(fd);
	return (mapp);
}

int	wall_check(t_map *map)
{
    int		i;
	size_t	col;

	col = map->cols - 2;
    // Vérifie si la première ligne ne contient que des '1'
    if (!ft_str_only_chr(map->map[0], '1'))
        return (0);

    // Vérifie si la dernière ligne ne contient que des '1'
    if (!ft_str_only_chr(map->map[map->line_map - 1], '1'))
        return (0);

    // Vérifie si la première et la dernière colonne ne contiennent que des '1'
    i = 0;
    while (i < map->line_map)
    {
		ft_printf("%c\n", map->map[i][map->cols - 2]);
        if (map->map[i][0] != '1' || map->map[i][col] != '1')
            return (0);
        i++;
    }
    return (1);
}

void	letter_number_check(t_map *map, char c, int y, int x)
{
	if (c == 'P' && map->spawn < 1)
	{
		map->spawn = 1;
		map->pos_p[0] = y;
		map->pos_p[1] = x;
	}
	else if (c == 'P' && map->spawn >= 1)
		map->spawn = 2;
	else if (c == 'E' && map->exit < 1)
	{
		map->exit = 1;
		map->pos_e[0] = y;
		map->pos_e[1] = x;
	}
	else if (c == 'E' && map->exit >= 1)
		map->exit = 2;
	else if (c == 'C')
		map->item++;
	else if (c == '0' || c == '1')
		map->valid = 0;
	else
		map->valid = 1;
}

int	rectangle_check(t_map *map)
{
	int		i;
	int		j;
	size_t	len;

	i = -1;
	j = -1;
	map->cols = ft_strlen((const char *)map->map[0]);
	ft_printf("cols: %d\n", (int)map->cols);
	if (map->line_map < 3)
	{
		ft_printf("La map doit contenir au moins 3 lignes\n");
		return (0);
	}
	else if (map->line_map == (int)map->cols)
	{
		ft_printf("La map ne doit pas etre un carrer\n");
		return (0);
	}
	while (map->map[++j] != NULL)
	{
		len = ft_strlen((const char *)map->map[j]);
		if (j == map->line_map - 1)
			len++;
		ft_printf("len %d : %d\n", j, (int)len);
		if (len != map->cols)
		{
			ft_printf("La map doit avoir le meme nombres de lignes\n");
			return (0);
		}
		while (map->map[j][++i] != 0)
		{
			letter_number_check(map, map->map[j][i], j, i);
		}
	}
	return (1);
}
