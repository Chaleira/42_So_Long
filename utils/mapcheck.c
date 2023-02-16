/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:11 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/16 19:45:00 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_sl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	checkwall(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	vars->map.width = ft_sl_strlen(vars->map.map[0]) - 1;
	while (y <= vars->map.height)
	{
		while (x <= vars->map.width)
		{
			if ((ft_sl_strlen(vars->map.map[y]) - 1) != vars->map.width)
			{
				ft_printf("Error\nNot All Walls Are The Same Size\n");
				return (0);
			}
			if (!error(vars, x, y, '1', "Error!\nMap Must Be Closed By Walls"))
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	if (!check_pce(vars))
		return (0);
	return (1);
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
