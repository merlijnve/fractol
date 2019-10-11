/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 16:26:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/11 13:26:26 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "math.h"
# include "../libft/srcs/libft.h"
# include <stdio.h>
# include <pthread.h>

# define WINX 1500
# define WINY 1200

/*
**	f == 1 == mandelbrot
**	f == 2 == julia
**	f == 3 == sierpinski
*/

typedef struct	s_hsv
{
	double		hh;
	double		ff;
	double		p;
	double		q;
	double		t;
	long		i;
}				t_hsv;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct	s_flag
{
	char		p;
}				t_flag;

typedef struct	s_fract
{
	int		f;
	int		iter;
	int		rand;
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	double	scale;
	double	xt;
	double	yt;
	int		section_y[WINY / 30];
	t_flag	flag;
}				t_fract;

int				loop_strcmp(char**argv, t_fract *frt);
int				key_press(int key, t_fract *frt);
int				mpress(int button, int x, int y, t_fract *frt);
void			draw(t_fract *frt);
void			imgpxlput(t_fract *frt, int color, int x, int y);
int				calc_point(t_fract *frt, int x, int y);
t_rgb			hsv_to_rgb(double hue, double sat, double value);
int				rgb_to_int(t_rgb rgb);
int				hsv_to_int(int hue, double sat, double value);
int				calc_mandelbrot(double x, double y, t_fract *frt);

#endif
