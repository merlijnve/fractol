/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 13:20:08 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/14 20:56:58 by mvan-eng      ########   odam.nl         */
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
	t_sect		*s;
	int			offset;

	x = 0;
	s = (t_sect *)sect;
	y = 0;
	offset = s->i * 30;
	while (y < 30)
	{
		while (x < WINX)
		{
			img_put(s->fract->adr, calc_iterations(x, y + offset, s->fract),
			x, y + offset);
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}

void	draw(t_fract *fract)
{
	pthread_t	thread[40];
	int			section;
	t_sect		sect[40];
	int			i;

	i = 0;
	section = 0;
	while (i < 40)
	{
		sect[i].fract = fract;
		sect[i].i = i;
		i++;
	}
	while (i > 0)
	{
		i--;
		pthread_create(&thread[i], NULL, draw_section, (void *)&sect[i]);
	}
	while (i < 40)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
