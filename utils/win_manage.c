/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:02 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 17:37:50 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

void	create_win(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 480, 480, "windoh");
	make_image(&vars);
	vars.img.x = 0;
	vars.img.y = 0;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 240, 240);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 240, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 0, 240);
	mlx_key_hook(vars.win, keyhook, &vars);
	mlx_loop(vars.mlx);
}
