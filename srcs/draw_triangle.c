/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_triangle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 13:18:44 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 15:14:31 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/draw_line.h"

void	draw_triangle(char *adr, int x, int y, int size)
{
	t_point p0;
	t_point	p1;
	t_point	p2;

	p0.x = x;
	p0.y = y;
	p1.x = x + size;
	p1.y = y;
	p2.x = x + (0.5 * size);
	p2.y = y - (0.5 * size * sqrt(3.0));
	draw_line(p0, p1, 0xffffff, adr);
	draw_line(p0, p2, 0xffffff, adr);
	draw_line(p1, p2, 0xffffff, adr);
}
