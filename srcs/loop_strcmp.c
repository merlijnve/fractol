/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_strcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 16:45:04 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/19 14:25:55 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Sets flag to corresponding fractal set, or returns -1
*/

int	loop_strcmp(char **argv, t_fract *frt)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		frt->f = 1;
	if (ft_strcmp("julia", argv[1]) == 0)
		frt->f = 2;
	if (ft_strcmp("sierpinski", argv[1]) == 0)
		frt->f = 3;
	if (frt->f != 1 && frt->f != 2 && frt->f != 3)
		return (-1);
	return (0);
}
