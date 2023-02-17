/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:02 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/17 17:26:41 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
	return (0);
}

void	create_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win_h = (vars->map.height + 1) * 64;
	vars->win_w = (vars->map.width + 1) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->win_w, vars->win_h, "windoh");
	make_image(vars);
	print_image(vars, 65364);
	mlx_key_hook(vars->win, keyhook, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_win, vars);
	mlx_loop(vars->mlx);
}

void	make_image(t_vars *vars)
{
	vars->img.type.player.front = mlx_xpm_file_to_image(vars->mlx,
			"sprites/front.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.player.back = mlx_xpm_file_to_image(vars->mlx,
			"sprites/back.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.player.left = mlx_xpm_file_to_image(vars->mlx,
			"sprites/left.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.player.right = mlx_xpm_file_to_image(vars->mlx,
			"sprites/right.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.ground = mlx_xpm_file_to_image(vars->mlx,
			"sprites/ground.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.wall = mlx_xpm_file_to_image(vars->mlx,
			"sprites/wall.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.collect = mlx_xpm_file_to_image(vars->mlx,
			"sprites/collect.xpm", &vars->img.w, &vars->img.h);
	vars->img.type.exit = mlx_xpm_file_to_image(vars->mlx,
			"sprites/exit.xpm", &vars->img.w, &vars->img.h);
}

int	error(t_vars *vars, int x, int y, char *str)
{
	if ((vars->map.map[0][x] != '1'
		|| vars->map.map[vars->map.height][x] != '1')
		|| vars->map.map[y][0] != '1'
		|| vars->map.map[y][vars->map.width] != '1')
	{
		ft_printf("%s\n", str);
		return (0);
	}
	return (1);
}
