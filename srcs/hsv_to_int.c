/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hsv_to_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/29 17:15:41 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/30 16:40:19 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				rgb_to_int(t_rgb rgb)
{
	int color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	return (color);
}

static t_rgb	set_rgb(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;
	return (rgb);
}

t_rgb			hsv_to_rgb(double hue, double sat, double value)
{
	t_hsv	hsv;
	t_rgb	rgb;

	hsv.hh = hue;
	if (hsv.hh >= 360.0)
		hsv.hh = 0.0;
	hsv.hh /= 60.0;
	hsv.i = (long)hsv.hh;
	hsv.ff = hsv.hh - hsv.i;
	hsv.p = value * (1.0 - sat);
	hsv.q = value * (1.0 - (sat * hsv.ff));
	hsv.t = value * (1.0 - (sat * (1.0 - hsv.ff)));
	if (hsv.i == 0)
		rgb = set_rgb(value, hsv.t, hsv.p);
	else if (hsv.i == 1)
		rgb = set_rgb(hsv.q, value, hsv.p);
	else if (hsv.i == 2)
		rgb = set_rgb(hsv.p, value, hsv.t);
	else if (hsv.i == 3)
		rgb = set_rgb(hsv.p, hsv.q, value);
	else if (hsv.i == 4)
		rgb = set_rgb(hsv.t, hsv.p, value);
	else
		rgb = set_rgb(value, hsv.p, hsv.q);
	return (rgb);
}

int				hsv_to_int(int hue, double sat, double value)
{
	return (rgb_to_int(hsv_to_rgb(hue, sat, value)));
}
