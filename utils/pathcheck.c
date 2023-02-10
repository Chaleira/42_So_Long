/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:18:41 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 04:51:04 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkPCE(t_map *map)
{
	t_PCE	pce;
	int		x;
	int		y;

	x = 0;
	y = 0;
	pce.p = 0;
	pce.c = 0;
	pce.e = 0;
	while (y <= map->height)
	{
		while (x <= map->width)
		{
			if (map->map[y][x] != 'P' && map->map[y][x] != 'C'
				&& map->map[y][x] != 'E'
				&& map->map[y][x] != '1' && map->map[y][x] != '0')
				return (0);
			if (map->map[y][x] == 'P')
			{
				pce.px = x;
				pce.py = y;
				pce.p++;
			}
			if (map->map[y][x] == 'C')
				pce.c++;
			if (map->map[y][x] == 'E')
				pce.e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (pce.p != 1 || pce.c < 1 || pce.e != 1)
		return (0);
	if (ispath(map, pce.px, pce.py))
		return (0);
	if (!path(map))
		return (0);
	return (1);
}

int	ispath(t_map *map, int x, int y)
{
	if (!(x >= 0 && x < map->width && y >= 0 && y < map->height
			&& map->map[y][x] != '1' && map->map[y][x] != '-'))
		return (0);
	map->map[y][x] = '-';
	if (ispath(map, x + 1, y) || ispath(map, x - 1, y)
		|| ispath(map, x, y + 1) || ispath(map, x, y - 1))
		return (1);
	return (0);
}

int	path(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= map->height)
	{
		while (x <= map->width)
		{
			if (map->map[y][x] == 'E' || map->map[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
