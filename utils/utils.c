/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:56:24 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/24 17:15:45 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	while (var.y < vars->map.height)
	{
		while (var.x < vars->map.width)
		{
			if (vars->map.mapcpy[var.y][var.x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.type.exit,
					var.x * 64, var.y * 64);
			var.x++;
		}
		var.y++;
		var.x = 0;
	}
}

int	ft_sl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	error(t_vars *vars, int x, int y, char *str)
{
	if ((vars->map.map[0][x] != '1'
		|| vars->map.map[vars->map.height - 1][x] != '1')
		|| vars->map.map[y][0] != '1'
		|| vars->map.map[y][vars->map.width - 1] != '1')
	{
		ft_printf("%s\n", str);
		return (0);
	}
	return (1);
}

void	counter(t_vars *vars)
{
	t_var	var;

	vars->map.pce.str_count = ft_itoa(vars->map.pce.c);
	var.i = 15;
	var.j = 20;
	while (var.i < 53)
	{
		while (var.j < 150)
		{
			mlx_pixel_put(vars->mlx, vars->win, var.j, var.i, 0xFFFFFF);
			var.j++;
		}
		var.j = 20;
		var.i++;
	}
	if (vars->map.pce.c == 0)
		exit_game(vars);
	mlx_string_put(vars->mlx, vars->win, 28, 45, 0xff0000, "Collect Count: ");
	mlx_string_put(vars->mlx, vars->win, 120, 45, 0xff0000,
		vars->map.pce.str_count);
	free (vars->map.pce.str_count);
}
