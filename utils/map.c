/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:57 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map(char	*argv, t_vars *vars)
{
	char	**map;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = get_matrix(fd, argv, vars);
	close(fd);
	return (map);
}

char	**get_matrix(int fd, char *argv, t_vars *vars)
{
	char		*str;
	t_var		var;

	var.j = 0;
	var.y = 0;
	var.i = 0;
	vars->map.height = 0;
	while (get_next_line(fd))
		var.y++;
	close(fd);
	vars->map.map = ft_calloc(sizeof(char *), var.y);
	fd = open(argv, O_RDONLY);
	vars->map.height = var.y - 1;
	while (var.y >= 0)
	{
		str = get_next_line(fd);
		vars->map.map[var.i] = str;
		var.i++;
		var.y--;
	}
	mapcopy(vars);
	if (!checkwall(vars))
		return (0);
	return (vars->map.mapcpy);
}

void	mapcopy(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->map.width = ft_sl_strlen(vars->map.map[0]) - 1;
	vars->map.mapcpy = ft_calloc(sizeof(char *), vars->map.height);
	while (y <= vars->map.height)
	{
		vars->map.mapcpy[y] = ft_calloc(sizeof(char), vars->map.width);
		while (x <= vars->map.width)
		{
			vars->map.mapcpy[y][x] = vars->map.map[y][x];
			x++;
		}
		vars->map.mapcpy[y][x] = '\n';
		x = 0;
		y++;
	}
}

int	ispath(t_vars *vars, int x, int y)
{
	if (!(x >= 0 && x < vars->map.width && y >= 0 && y < vars->map.height
			&& vars->map.map[y][x] != '1' && vars->map.map[y][x] != '-'))
		return (0);
	vars->map.map[y][x] = '-';
	if (ispath(vars, x + 1, y) || ispath(vars, x - 1, y)
		|| ispath(vars, x, y + 1) || ispath(vars, x, y - 1))
		return (1);
	return (0);
}

int	path(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= vars->map.height)
	{
		while (x <= vars->map.width)
		{
			if (vars->map.map[y][x] == 'E' || vars->map.map[y][x] == 'C')
			{	
				ft_printf("Error!\nNo Path To Exit Or Collectible\n");
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
