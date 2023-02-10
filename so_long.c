/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:15:56 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 05:10:01 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int key, t_vars *vars)
{
	if (key == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	if (key == 65364)
	{
		vars->img.y += 20;
        print_image(vars->img.type.player.front, vars->img.x, vars->img.y, vars);
	}
	if (key == 65363)
	{
		vars->img.x += 20;
        print_image(vars->img.type.player.right, vars->img.x, vars->img.y, vars);
	}
	if (key == 65362)
	{
		vars->img.y -= 20;
        print_image(vars->img.type.player.back, vars->img.x, vars->img.y, vars);
	}
	if (key == 65361)
	{
		vars->img.x -= 20;
        print_image(vars->img.type.player.left, vars->img.x, vars->img.y, vars);
	}
	return (0);
}

void	print_image(void *image, int x, int y, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.ground, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.ground, 240, 240);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.ground, 240, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.type.ground, 0, 240);
	mlx_put_image_to_window(vars->mlx, vars->win, image, x, y);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 480, 480, "windoh");
	vars.img.type.player.front = mlx_xpm_file_to_image(vars.mlx, "sprites/front.xpm", &vars.img.w, &vars.img.h);
	vars.img.type.player.back = mlx_xpm_file_to_image(vars.mlx, "sprites/back.xpm", &vars.img.w, &vars.img.h);
	vars.img.type.player.left = mlx_xpm_file_to_image(vars.mlx, "sprites/left.xpm", &vars.img.w, &vars.img.h);
	vars.img.type.player.right = mlx_xpm_file_to_image(vars.mlx, "sprites/right.xpm", &vars.img.w, &vars.img.h);
	vars.img.type.ground = mlx_xpm_file_to_image(vars.mlx, "sprites/ground.xpm", &vars.img.w, &vars.img.h);
	vars.img.type.wall = mlx_xpm_file_to_image(vars.mlx, "sprites/wall.xpm", &vars.img.w, &vars.img.h);
	vars.img.x = 0;
	vars.img.y = 0;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 240, 240);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 240, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.type.ground, 0, 240);
	mlx_key_hook(vars.win, keyhook, &vars);
	mlx_loop(vars.mlx);
}
