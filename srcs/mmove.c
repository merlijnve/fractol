/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mmove.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 18:19:00 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/14 18:28:13 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
