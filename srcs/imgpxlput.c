/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imgpxlput.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 18:59:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/30 21:16:03 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Pixelput for image use, copies a given color to the correct location
**	in memory set by mlx_get_data_addr
*/

// void	imgpxlput(t_fract *frt, int color, int x, int y)
// {
// 	char	*adr;

// 	adr = frt->adr;
// 	ft_memcpy(&adr[(4 * x + (4 * WINX * y))], &color, 4);
// }

void	imgpxlput(t_fract *frt, int color, int x, int y)
{
	char	*adr;

	adr = frt->adr;
	ft_memcpy(&adr[(4 * x + (4 * WINX * y))], &color, 4);
}
