/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:00:18 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/24 11:00:46 by plopes-c         ###   ########.fr       */
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
	vars->win = mlx_new_window(vars->mlx, vars->win_w, vars->win_h, "so_long");
	make_image(vars);
	print_image(vars, 65364);
	mlx_hook(vars->win, 2, 1L << 0, keyhook, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_win, vars);
	mlx_hook(vars->win, 25, 1L << 18, keyhook, vars);
	mlx_loop(vars->mlx);
}
