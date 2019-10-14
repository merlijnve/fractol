/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:20:08 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/14 15:06:51 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/draw_line.h"
/*
**	Draws section of 30 pixels
*/

void	*draw_section(void *sect)
{
	int			x;
	int			y;
	static int	i = 0;
	t_fract		*fract;

	x = 0;
	fract = (t_fract *)sect->fract;
	y = 0;
	printf("Y: %d, i: %d,\n", y, i);
	while (y < 30)
	{
		while (x < WINX)
		{
			img_put(fract->adr, calc_mandelbrot(x, y + i * 30,
			fract), x, y + i * 30);
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
	int			section;
	t_sect		sect;

	section = 0;
	sect.fract = fract;
	sect.i = 0;
	if (fract->f == 3)
		draw_sierpinski(fract);
	else if (fract->f == 1)
	{
		while (sect.i < 40)
		{
			draw_section(fract);
			//pthread_create(&thread[i], NULL, draw_section, (void *)&sect);
			sect.i++;
		}
		sect.i = 0;
		while (sect.i < 40)
		{
			pthread_join(thread[sect.i], NULL);
			sect.i++;
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
