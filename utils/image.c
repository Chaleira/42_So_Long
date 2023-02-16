/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:04:48 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/16 18:45:11 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_image(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	background (vars);
	walls(vars);
	collect(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.player.front,
		vars->map.pce.px * 64, vars->map.pce.py * 64);
	if (vars->map.pce.c == 0)
		exit_game(vars);
	mlx_string_put(vars->mlx, vars->win, 28, 35, 0xff0000, ft_itoa(vars->map.pce.move_count));
}

void	background(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	while (var.x <= vars->win_w)
	{
		while (var.y <= vars->win_h)
		{
			mlx_put_image_to_window(vars->mlx,
				vars->win, vars->img.type.ground, var.x, var.y);
			var.y += 64;
		}
		var.x += 64;
		var.y = 0;
	}
}

void	walls(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	while (var.y <= vars->map.height)
	{
		while (var.x <= vars->map.width)
		{
			if (vars->map.mapcpy[var.y][var.x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.type.wall,
					var.x * 64, var.y * 64);
			var.x++;
		}
		var.y++;
		var.x = 0;
	}
}

void	collect(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	while (var.y <= vars->map.height)
	{
		while (var.x <= vars->map.width)
		{
			if (vars->map.mapcpy[var.y][var.x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.type.collect,
					var.x * 64, var.y * 64);
			var.x++;
		}
		var.y++;
		var.x = 0;
	}
}

void	exit_game(t_vars *vars)
{
	t_var	var;

	var.x = 0;
	var.y = 0;
	while (var.y <= vars->map.height)
	{
		while (var.x <= vars->map.width)
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