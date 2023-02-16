/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:15:56 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/16 19:39:02 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_vars *vars, int x, int y)
{
	x += vars->map.pce.px;
	y += vars->map.pce.py;
	if (vars->map.mapcpy[y][x] == 'E' && vars->map.pce.c == 0)
		exit(0);
	if (vars->map.mapcpy[y][x] != '1')
	{
		if (vars->map.mapcpy[y][x] == 'C')
		{
			vars->map.pce.c--;
			vars->map.mapcpy[y][x] = '0';
		}
		vars->map.pce.px = x;
		vars->map.pce.py = y;
		vars->map.pce.move_count++;
		return (1);
	}
	return (0);
}

int	keyhook(int key, t_vars *vars)
{
	if (key == 65307)
		close_win(vars);
	if (key == 65364 && check_move(vars, 0, 1))
		print_image(vars);
	if (key == 65363 && check_move(vars, 1, 0))
		print_image(vars);
	if (key == 65362 && check_move(vars, 0, -1))
		print_image(vars);
	if (key == 65361 && check_move(vars, -1, 0))
		print_image(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.map.pce.move_count = 0;
	(void)argc;
	if (map(argv[1], &vars))
		create_win(&vars);
	else
		exit (0);
	return (0);
}
