/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:54:15 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/24 10:58:34 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkwallsize(t_vars *vars)
{
	int	y;

	y = 1;
	while (y <= vars->map.height)
	{
		if ((ft_sl_strlen(vars->map.map[y]) - 1) != vars->map.width)
		{
			ft_printf("Error!\nNot All Walls Are The Same Size\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	checkwall(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	vars->map.width = ft_sl_strlen(vars->map.map[0]) - 1;
	if (!checkwallsize(vars))
		return (0);
	while (y <= vars->map.height)
	{
		while (x <= vars->map.width)
		{
			if (!error(vars, x, y, "Error!\nMap Must Be Closed By Walls"))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (!check_pce(vars))
		return (0);
	return (1);
}

int	check_pce(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	vars->map.pce.p = 0;
	vars->map.pce.c = 0;
	vars->map.pce.e = 0;
	while (var.y <= vars->map.height)
	{
		while (var.x <= vars->map.width)
		{
			if (!count_pce(vars, var.x, var.y))
				return (0);
			var.x++;
		}
		var.x = 0;
		var.y++;
	}
	return (pce_aux(vars));
}

int	count_pce(t_vars *vars, int x, int y)
{
	if (vars->map.map[y][x] != 'P' && vars->map.map[y][x] != 'C'
		&& vars->map.map[y][x] != 'E'
		&& vars->map.map[y][x] != '1' && vars->map.map[y][x] != '0')
	{
		ft_printf("Error\nInvalid Characters\n");
		return (0);
	}
	if (vars->map.map[y][x] == 'P')
	{
		vars->map.pce.px = x;
		vars->map.pce.py = y;
		vars->map.pce.p++;
	}
	if (vars->map.map[y][x] == 'C')
		vars->map.pce.c++;
	if (vars->map.map[y][x] == 'E')
		vars->map.pce.e++;
	return (1);
}

int	pce_aux(t_vars	*vars)
{
	if (vars->map.pce.p != 1)
	{
		ft_printf("Error\nInvalid Player number!\n");
		return (0);
	}
	if (vars->map.pce.c < 1)
	{
		ft_printf("Error\nInvalid Collectible number!\n");
		return (0);
	}
	if (vars->map.pce.e != 1)
	{
		ft_printf("Error\nInvalid Exit number!\n");
		return (0);
	}
	if (ispath(vars, vars->map.pce.px, vars->map.pce.py))
		return (0);
	if (!path(vars))
		return (0);
	return (1);
}
