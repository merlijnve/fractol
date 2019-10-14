/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 13:41:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 15:00:46 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/draw_line.h"

static void	ft_drawline_h(t_point p0, t_point p1, int color, char *address)
{
	t_line	line;

	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	line.i = 1;
	if (line.dx < 0)
	{
		line.i = -1;
		line.dx = line.dx * -1;
	}
	line.d = 2 * line.dx - line.dy;
	line.x = p0.x;
	line.y = p0.y;
	while (line.y <= p1.y)
	{
		if (line.x > 0 && line.x < WINX && line.y > 0 && line.y < WINY)
			img_put(address, color, line.x, line.y);
		if (line.d > 0)
		{
			line.x += line.i;
			line.d -= 2 * line.dy;
		}
		line.d += 2 * line.dx;
		line.y++;
	}
}

static void	ft_drawline_l(t_point p0, t_point p1, int color, char *address)
{
	t_line line;

	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	line.i = 1;
	if (line.dy < 0)
	{
		line.i = -1;
		line.dy = line.dy * -1;
	}
	line.d = 2 * line.dy - line.dx;
	line.y = p0.y;
	line.x = p0.x;
	while (line.x <= p1.x)
	{
		if (line.x > 0 && line.x < WINX && line.y > 0 && line.y < WINY)
			img_put(address, color, line.x, line.y);
		if (line.d > 0)
		{
			line.y += line.i;
			line.d -= 2 * line.dx;
		}
		line.d += 2 * line.dy;
		line.x++;
	}
}

void		draw_line(t_point p0, t_point p1, int color, char *address)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_drawline_l(p1, p0, color, address);
		else
			ft_drawline_l(p0, p1, color, address);
	}
	else
	{
		if (p0.y > p1.y)
			ft_drawline_h(p1, p0, color, address);
		else
			ft_drawline_h(p0, p1, color, address);
	}
}
