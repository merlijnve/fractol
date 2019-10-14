/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 13:29:36 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 14:57:30 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		d;
	int		i;
}				t_line;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

void			draw_line(t_point p0, t_point p1, int color, char *address);

#endif
