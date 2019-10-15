/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:23:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/15 15:04:09 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Handle keypress
**	- exit (esc)
*/

void	move_fractal(int key, t_fract *fract)
{
	if (key == 123)
		fract->xt -= 30.0 / fract->scale;
	if (key == 124)
		fract->xt += 30.0 / fract->scale;
	if (key == 126)
		fract->yt -= 30.0 / fract->scale;
	if (key == 125)
		fract->yt += 30.0 / fract->scale;
}

int		key_press(int key, t_fract *fract)
{
	if (key == 53)
		exit(0);
	if (key == 11)
		fract->flag.b = fract->flag.b == 0 ? 1 : 0;
	if (key == 35)
		fract->flag.p *= -1;
	if (key == 27)
		fract->iter -= 50;
	if (key == 24)
		fract->iter += 50;
	move_fractal(key, fract);
	if (key == 27 || key == 24 || key == 35 || key == 123 || key == 124 ||
	key == 126 || key == 125 || key == 123 || key == 11)
	{
		mlx_clear_window(fract->mlx, fract->win);
		draw(fract);
	}
	ft_putnbr(key);
	return (0);
}

int		mmove(int x, int y, t_fract *fract)
{
	if (fract->flag.mp == -1)
	{
		fract->mx = (double)x;
		fract->my = (double)y;
		mlx_clear_window(fract->mlx, fract->win);
		draw(fract);
	}
	return (0);
}

int		mpress(int button, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (button == 4)
		fract->scale *= 1.1;
	if (button == 5)
		fract->scale *= 0.9;
	if (button == 1)
		fract->flag.mp *= -1;
	mlx_clear_window(fract->mlx, fract->win);
	draw(fract);
	return (0);
}
