/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:15:56 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 18:06:57 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int key, t_vars *vars)
{
	if (key == 65307)
		close_win(vars);
	if (key == 65364)
		move_up(vars);
	if (key == 65363)
		move_right(vars);
	if (key == 65362)
		move_down(vars);
	if (key == 65361)
		move_left(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (map(argv[1]))
		create_win();
	else
		ft_printf("erro\n");
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	int		i;
// 	char	**map;

// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	map = get_matrix(fd, argv[1]);
// 	if (!map)
// 	{
// 		ft_printf("\nno map\n");
// 		return (0);
// 	}
// 	ft_printf("\nwe have a map\n");
// 	close(fd);
// 	return (0);
// }