/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:38:21 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/10 04:55:05 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <memory.h>

typedef struct s_player
{
	void	*front;
	void	*back;
	void	*right;
	void	*left;
}				t_player;

typedef struct s_type
{
	void		*ground;
	void		*wall;
	void		*collect;
	t_player	player;
}				t_type;

typedef struct map
{
	int			height;
	int			width;
	char		**map;
	char		**mapcpy;
}			t_map;

typedef struct PCE
{
	int	p;
	int	c;
	int	e;
	int	px;
	int	py;
	int	ex;
	int	ey;
}			t_PCE;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	int			h;
	int			w;
	t_type		type;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_vars;

int		ft_sl_strlen(char *s);
int		checkwall(t_map *map);
char	**get_matrix(int fd, char *argv);
int		checkPCE(t_map *map);
int		ispath(t_map *map, int x, int y);
int		path(t_map *map);
int		isafe(int x, int y, t_map *map);
void	mapcopy(t_map *map);
int		close_win(int key, t_vars *vars);
void	print_image(void *image, int x, int y, t_vars *vars);
int	    keyhook(int key, t_vars *vars);

#endif