/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 04:50:56 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_sl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	checkwall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->width = ft_sl_strlen(map->map[0]) - 1;
	while (y <= map->height)
	{
		while (x <= map->width)
		{
			if (map->map[0][x] != '1' || map->map[map->height][x] != '1')
				return (0);
			x++;
		}
		if (map->map[y][0] != '1' || map->map[y][map->width] != '1'
			|| (ft_sl_strlen(map->map[y]) - 1) != map->width)
			return (0);
		y++;
		x = 0;
	}
	if (!checkPCE(map))
		return (0);
	return (1);
}

char	**get_matrix(int fd, char *argv)
{
	char		*str;
	t_map		map;
	int			height;
	int			i;
	int			j;

	j = 0; 
	height = 0;
	i = 0;
	map.height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	map.map = ft_calloc(sizeof(char *), height);
	fd = open(argv, O_RDONLY);
	map.height = height - 1;
	while (height >= 0)
	{
		str = get_next_line(fd);
		map.map[i] = str;
		i++;
		height--;
	}
	mapcopy(&map);
	if (!checkwall(&map))
		return (0);
	return (map.mapcpy);
}

void	checkfd(int fd, char *argv[])
{
	if (fd > -1)
		get_matrix(fd, argv[1]);
}

void	mapcopy(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->width = ft_sl_strlen(map->map[0]) - 1;
	map->mapcpy = ft_calloc(sizeof(char *), map->height);
	while (y <= map->height)
	{
		map->mapcpy[y] = ft_calloc(sizeof(char), map->width);
		while (x <= map->width)
		{
			map->mapcpy[y][x] = map->map[y][x];
			x++;
		}
		map->mapcpy[y][x] = '\n';
		x = 0;
		y++;
	}
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	int		i;
// 	char	**map;

// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	map = get_matrix(fd, argv[1]);
// 	if (!map)
// 	{
// 		ft_printf("\nno map\n");
// 		return (0);
// 	}
// 	ft_printf("\nwe have a map\n");
// 	close(fd);
// 	return (0);
// }

// aashduhasd