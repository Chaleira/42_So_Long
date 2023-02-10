/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:23:25 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 17:28:39 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_vars	*vars)
{
	vars->img.x += 20;
	print_image(vars->img.type.player.right,
		vars->img.x, vars->img.y, vars);
}

void	move_up(t_vars	*vars)
{
	vars->img.y += 20;
	print_image(vars->img.type.player.front,
		vars->img.x, vars->img.y, vars);
}

void	move_down(t_vars	*vars)
{
	vars->img.y -= 20;
	print_image(vars->img.type.player.back,
		vars->img.x, vars->img.y, vars);
}

void	move_left(t_vars	*vars)
{
	vars->img.x -= 20;
	print_image(vars->img.type.player.left,
		vars->img.x, vars->img.y, vars);
}
