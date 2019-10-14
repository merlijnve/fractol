/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mpress.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:00:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 13:39:21 by mvan-eng      ########   odam.nl         */
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
	{
		fract->scale += 250;
	}
	if (button == 5)
	{
		fract->scale -= 250;
	}
	mlx_clear_window(fract->mlx, fract->win);
	draw(fract);
	return (0);
}
