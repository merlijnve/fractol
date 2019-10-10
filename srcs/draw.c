/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:20:08 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/01 20:00:11 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Draws section of 30 pixels
*/

void	*draw_section(void *fract)
{
	int		x;
	int		y;
	t_fract	*frt;

	x = 0;
	frt = (t_fract *)fract;
	y = 0;
	while (y < 30)
	{
		while (x < WINX)
		{
			imgpxlput(fract, calc_mandelbrot(x, y + frt->section_y, fract),
			x, y + frt->section_y);
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}

void	draw(t_fract *fract)
{
	pthread_t	thread[1];
	int			i;

	i = 0;
	fract->section_y = 0;
	while (fract->section_y < 30)
	{
		pthread_create(&thread[i], NULL, draw_section, (void *)fract);
		i++;
		fract->section_y += 30;
	}
	pthread_join(thread[0], NULL);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
