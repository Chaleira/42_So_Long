/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:33:33 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/16 18:30:14 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map(char	*argv, t_vars *vars)
{
	char	**map;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = get_matrix(fd, argv, vars);
	close(fd);
	return (map);
}
