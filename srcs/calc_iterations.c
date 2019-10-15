/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_iterations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/29 20:20:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/15 17:55:16 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		calc_mandelbrot(double x, double y, t_fract *fract)
{
	int		iter;
	double	zx;
	double	zy;
	double	zx2;
	double	ozy;

	zx = 0.0;
	zy = 0.0;
	x = x / (300.0 + fract->scale) - 1.0 + fract->xt;
	y = y / (300.0 + fract->scale) - 1.0 + fract->yt;
	iter = 0;
	zx2 = zx * zx;
	while (iter < fract->iter && (zx2 + (zy * zy)) < 4.0)
	{
		ozy = zy;
		zy = 2.0 * zx * zy + y;
		zx = zx2 - (ozy * ozy) + x;
		zx2 = zx * zx;
		iter++;
	}
	if ((zx * zx) + (zy * zy) < 4.0)
		return (0);
	if (fract->flag.p == -1)
		return (hsv_to_int(30 * (1 - log10(zy + zx)), 0.6, 1.0));
	return (hsv_to_int(iter + 180 * fract->flag.b, 0.6, 1.0));
}

int		calc_julia(double x, double y, t_fract *fract)
{
	int		iter;
	double	zx;
	double	zy;
	double	zx2;
	double	ozy;

	zx = (x - 0.5 * WINX + fract->scale) / 400.0;
	zy = (y - 0.5 * WINY + fract->scale) / 400.0;
	x = fract->mx / 300.0 - 2;
	y = fract->my / 375.0 - 2;
	iter = 0;
	zx2 = zx * zx;
	while (iter < fract->iter && (zx2 + (zy * zy)) < 4.0)
	{
		ozy = zy;
		zy = 2.0 * zx * zy + y;
		zx = zx2 - (ozy * ozy) + x;
		zx2 = zx * zx;
		iter++;
	}
	if ((zx * zx) + (zy * zy) < 4.0)
		return (0);
	if (fract->flag.p == -1)
		return (hsv_to_int(180 + 10 * sqrt(log(zx2 * zx)), 0.6, 1.0));
	return (hsv_to_int(iter + fract->flag.b * 180, 0.6, 1.0));
}

int		calc_ship(double x, double y, t_fract *fract)
{
	int		iter;
	double	zx;
	double	zy;
	double	zx2;
	double	ozy;

	zx = 0.0;
	zy = 0.0;
	x = x / (300.0 + fract->scale) - 1.0 + fract->xt;
	y = y / (300.0 + fract->scale) - 1.0 + fract->yt;
	iter = 0;
	zx2 = zx * zx;
	while (iter < fract->iter && (zx2 + (zy * zy)) < 4.0)
	{
		ozy = zy;
		zy = fabs(2.0 * zx * zy + y);
		zx = fabs(zx2 - (ozy * ozy) + x);
		zx2 = zx * zx;
		iter++;
	}
	if ((zx * zx) + (zy * zy) < 4.0)
		return (0);
	if (fract->flag.p == -1)
		return (hsv_to_int(30 * (1 - log10(zy + zx)), 0.6, 1.0));
	return (hsv_to_int(iter + 180 * fract->flag.b, 0.6, 1.0));
}

int		calc_ship_julia(double x, double y, t_fract *fract)
{
	int		iter;
	double	zx;
	double	zy;
	double	zx2;
	double	ozy;

	zx = (x - 0.5 * WINX + fract->scale) / 400.0;
	zy = (y - 0.5 * WINY + fract->scale) / 400.0;
	x = fract->mx / 300.0 - 2;
	y = fract->my / 375.0 - 2;
	iter = 0;
	zx2 = zx * zx;
	while (iter < fract->iter && (zx2 + (zy * zy)) < 4.0)
	{
		ozy = zy;
		zy = fabs(2.0 * zx * zy + y);
		zx = fabs(zx2 - (ozy * ozy) + x);
		zx2 = zx * zx;
		iter++;
	}
	if ((zx * zx) + (zy * zy) < 4.0)
		return (0);
	if (fract->flag.p == -1)
		return (hsv_to_int(180 + 10 * sqrt(log(zx2 * zx)), 0.6, 1.0));
	return (hsv_to_int(iter + fract->flag.b * 180, 0.6, 1.0));
}

int		calc_iterations(double x, double y, t_fract *fract)
{
	int	color;

	if (fract->f == 1)
		color = calc_mandelbrot(x, y, fract);
	if (fract->f == 2)
		color = calc_julia(x, y, fract);
	if (fract->f == 3)
		color = calc_ship_julia(x, y, fract);
	return (color);
}
