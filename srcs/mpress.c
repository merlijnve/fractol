/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mpress.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:00:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/14 20:43:13 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Handling mousepress, sets the coordinates clicked
*/

int		mpress(int button, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (button == 4)
		fract->scale += 350;
	if (button == 5)
		fract->scale -= 350;
	if (button == 1)
		fract->flag.mp *= -1;
	mlx_clear_window(fract->mlx, fract->win);
	draw(fract);
	return (0);
}
