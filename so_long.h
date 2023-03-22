/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:38:21 by plopes-c          #+#    #+#             */
/*   Updated: 2023/03/08 10:15:42 by plopes-c         ###   ########.fr       */
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
	int		p;
	int		c;
	int		cc;
	int		e;
	int		move_count;
	char	*str_count;
	int		px;
	int		py;
	int		ex;
	int		ey;
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

int		map(char	*argv, t_vars *vars);
int		get_matrix(int fd, char *argv, t_vars *vars);
void	mapcopy(t_vars *map);
int		ispath(t_vars *vars, int x, int y);
int		path(t_vars *vars);

int		checkwallsize(t_vars *vars);
int		checkwall(t_vars *vars);
int		check_pce(t_vars *vars);
int		count_pce(t_vars *vars, int x, int y);
int		pce_aux(t_vars	*vars);

void	exit_game(t_vars *vars);
int		ft_sl_strlen(char *s);
int		error(t_vars *vars, int x, int y, char *str);
void	counter(t_vars *vars);

void	collect(t_vars *vars);
void	background(t_vars *vars);
void	walls(t_vars *vars);
void	print_image(t_vars *vars, int key);
void	make_image(t_vars *vars);

int		close_win(t_vars *vars);
void	create_win(t_vars *vars);

int		keyhook(int key, t_vars *vars);
int		check_move(t_vars *vars, int x, int y);

void	free_map(char **map);
void	destroy_img(t_vars *vars);
int		free_str(int fd);

#endif