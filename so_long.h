/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:38:21 by plopes-c          #+#    #+#             */
/*   Updated: 2023/02/16 19:28:32 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <memory.h>

typedef struct s_var
{
	int	x;
	int	y;
	int	i;
	int	j;
}				t_var;

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
	void		*exit;
	t_player	player;
}				t_type;

typedef struct s_PCE
{
	int	p;
	int	c;
	int	e;
	int	move_count;
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

typedef struct s_map
{
	int			fd;
	int			height;
	int			width;
	char		**map;
	char		**mapcpy;
	t_PCE		pce;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;
	t_map	map;
	t_img	img;
}				t_vars;

int		ft_sl_strlen(char *s);
int		checkwall(t_vars *vars);
char	**get_matrix(int fd, char *argv, t_vars *vars);
int		check_pce(t_vars *vars);
int		ispath(t_vars *vars, int x, int y);
int		path(t_vars *vars);
int		isafe(int x, int y, t_map *map);
void	mapcopy(t_vars *map);
void	close_win(t_vars *vars);
void	print_image(t_vars *vars);
int		keyhook(int key, t_vars *vars);
void	make_image(t_vars *vars);
void	create_win(t_vars *vars);
char	**map(char	*argv, t_vars *vars);
int		count_pce(t_vars *vars, int x, int y);
int		pce_aux(t_vars	*vars);
void	background(t_vars *vars);
void	walls(t_vars *vars);
void	collect(t_vars *vars);
void	exit_game(t_vars *vars);
int		error(t_vars *vars, int x, int y, char c, char *str);

#endif