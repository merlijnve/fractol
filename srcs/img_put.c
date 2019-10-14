/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_put.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 18:59:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/12 13:43:26 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Pixelput for image use, copies a given color to the correct location
**	in memory set by mlx_get_data_addr
*/

void	img_put(char *address, int color, int x, int y)
{
	ft_memcpy((void *)&address[(4 * x + (4 * WINX * y))], &color, 4);
}
