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

void	remplir_tableau(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = line;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
}

char	**tableau_map(t_map *map)
{
	int		fd;
	char	*line;
	char	**mapp;

	fd = open(map->path_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	map->line_map = 0;
	while (line != NULL)
	{
		map->line_map++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map = (char **)malloc((map->line_map + 1) * sizeof(char *));
	if (!map->map)
		return (NULL);
	fd = open(map->path_map, O_RDONLY);
	remplir_tableau(map->map, fd);
	close(fd);
	return (mapp);
}

int	wall_check(t_map *map)
{
	int	i;

	i = -1;
	if (ft_str_only_chr(map->map[0], '1') || ft_str_only_chr(map->map[-1], '1'))
		return (0);
	else
	{
		while (map->map[++i][0] == '1' && map->map[i][-1] == '1' && map->map[i] != NULL);
		if (i + 1 == map->line_map)
			return (1);
		else
			return (0);
	}
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
	int		check;
	size_t	len;

	i = -1;
	j = 0;
	map->cols = ft_strlen((const char *)map->map[0]);
	if (map->line_map < 3)
		return (0);
	else if (map->line_map == map->cols)
		return (0);
	while (map->map[++j] != NULL)
	{
		len = ft_strlen((const char *)map->map[j]);
		if (len != map->cols)
			return (0);
		while (map->map[j][++i] != NULL)
		{
			letter_number_check(map, map->map[j][i], j, i);
		}
	}
	return (1);
}
