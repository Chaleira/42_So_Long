/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:04:48 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 17:22:53 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_image(void *image, int x, int y, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.ground, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.type.ground, 240, 240);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.type.ground, 240, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.type.ground, 0, 240);
	mlx_put_image_to_window(vars->mlx, vars->win, image, x, y);
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
}