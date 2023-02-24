/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:23:22 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/24 17:29:01 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
}

void	destroy_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.type.collect);
	mlx_destroy_image(vars->mlx, vars->img.type.player.front);
	mlx_destroy_image(vars->mlx, vars->img.type.player.back);
	mlx_destroy_image(vars->mlx, vars->img.type.player.left);
	mlx_destroy_image(vars->mlx, vars->img.type.player.right);
	mlx_destroy_image(vars->mlx, vars->img.type.wall);
	mlx_destroy_image(vars->mlx, vars->img.type.ground);
	mlx_destroy_image(vars->mlx, vars->img.type.exit);
}

int	free_str(int fd)
{
	char	*str;
	int		y;

	y = 0;
	str = get_next_line(fd);
	while (str && ++y)
	{
		free (str);
		str = get_next_line(fd);
	}
	free (str);
	return (y);
}
