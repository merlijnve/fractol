/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:23:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 13:39:21 by mvan-eng      ########   odam.nl         */
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
		fract->xt += 50;
	if (key == 124)
		fract->xt -= 50;
	if (key == 126)
		fract->yt += 50;
	if (key == 125)
		fract->yt -= 50;
}

int		key_press(int key, t_fract *fract)
{
	if (key == 53)
		exit(0);
	if (key == 35)
		fract->flag.p *= -1;
	if (key == 27)
		fract->iter -= 50;
	if (key == 24)
		fract->iter += 50;
	move_fractal(key, fract);
	if (key == 27 || key == 24 || key == 35 || key == 123 || key == 124 ||
	key == 126 || key == 125 || key == 123)
	{
		mlx_clear_window(fract->mlx, fract->win);
		draw(fract);
	}
	ft_putnbr(key);
	return (0);
}
