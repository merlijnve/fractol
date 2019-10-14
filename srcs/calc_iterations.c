/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_iterations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/29 20:20:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/14 15:00:46 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		calc_mandelbrot(double x, double y, t_fract *fract)
{
	int		iter;
	double	zx;
	double	zy;
	double	ozy;
	double	zx2;

	zx = 0.0;
	zy = 0.0;
	x = (x - 900.0 - fract->xt) / fract->scale;
	y = (y - 600.0 - fract->yt) / fract->scale;
	iter = 0;
	while (iter < fract->iter && (zx2 + (zy * zy)) < 4.0)
	{
		zx2 = zx * zx;
		ozy = zy;
		zy = 2.0 * zx * zy + y;
		zx = zx2 - (ozy * ozy) + x;
		//zx2 = zx * zx;
		iter++;
	}
	if ((zx * zx) + (zy * zy) < 4.0)
		return (0);
	if (fract->flag.p == -1)
		return (hsv_to_int(30 * (1 - log10(zy + zx)), 0.6, 1.0));
	return (hsv_to_int(iter, 0.6, 1.0));
}
