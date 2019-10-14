/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_sierpinski.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 15:40:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 17:25:47 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/draw_line.h"

t_point		rotate_point(double deg, t_point p0, int len)
{
	double	rad;
	double	c;
	double	s;
	t_point	p1;
	t_point	p2;

	rad = M_PI / 180;
	c = cos(deg * rad);
	s = sin(deg * rad);
	p1.x = 0;
	p1.y = -len;
	p2.x = p1.x * c - p1.y * s;
	p2.y = p1.x * s + p1.y * c;
	p2.x += p0.x;
	p2.y += p0.y;
	return (p2);
}

int			draw_branch(t_point p0, int len, int angle, char *adr)
{
	t_point p1;
	t_point p2;

	if (len < 1)
		return (0);
	p1 = rotate_point(angle, p0, len);
	p2 = rotate_point(-angle, p0, len);
	draw_line(p0, p1, 0xffffff, adr);
	draw_line(p0, p2, 0xffffff, adr);
	draw_branch(p1, len * 0.8, angle + 30, adr);
	draw_branch(p2, len * 0.8, angle + 30, adr);
	return (0);
}

void		draw_sierpinski(t_fract *fract)
{
	t_point	mid;

	mid.x = WINX / 2;
	mid.y = WINY / 2;
	draw_branch(mid, 200, 10, fract->adr);
}
