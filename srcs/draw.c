/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:20:08 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/11 17:47:26 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Draws section of 30 pixels
*/

void	*draw_section(void *fract)
{
	int			x;
	int			y;
	static int	i = 0;
	t_fract		*frt;

	x = 0;
	frt = (t_fract *)fract;
	y = frt->section_y[i];
	printf("Y: %d, i: %d,\n", y, i);
	while (y < 30)
	{
		while (x < WINX)
		{
			imgpxlput(fract, calc_mandelbrot(x, y + frt->section_y[i], fract),
			x, y + frt->section_y[i]);
			x++;
		}
		x = 0;
		y++;
	}
	i++;
	if (i == 40)
		i = 0;
	return (NULL);
}

void	draw(t_fract *fract)
{
	pthread_t	thread[40];
	int			i;
	int			section;

	section = 0;
	i = 0;
	while (i < 40)
	{
		fract->section_y[i] = section;
		section += 30;
		i++;
	}
	i = 0;
	while (i < 40)
	{
		pthread_create(&thread[i], NULL, draw_section, (void *)fract);
		i++;
	}
	i = 0;
	while (i < 40)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
