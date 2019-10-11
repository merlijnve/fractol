/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:55:49 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/10/11 15:57:46 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_flags(t_fract *frt)
{
	frt->flag.p = 1;
}

int		initialize_data(t_fract *frt)
{
	int	temp;

	temp = 0;
	frt->mlx = mlx_init();
	frt->iter = 200;
	frt->scale = 800.0;
	frt->xt = 150;
	frt->yt = 0;
	initialize_flags(frt);
	if (frt->mlx == NULL)
		return (-1);
	frt->win = mlx_new_window(frt->mlx, WINX, WINY, "fractal");
	frt->img = mlx_new_image(frt->mlx, WINX, WINY);
	if (frt->win == NULL || frt->img == NULL)
		return (-1);
	frt->adr = mlx_get_data_addr(frt->img, &temp, &temp, &temp);
	if (frt->img == NULL)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fract *frt;

	frt = (t_fract *)malloc(sizeof(t_fract));
	if (argc != 2 || loop_strcmp(argv, frt) == -1)
	{
		ft_putendl("Usage: ./fractol [fractal name]\n");
		ft_putendl("Available fractals:\n- mandelbrot\n- julia\n- sierpinski");
		free(frt);
		return (0);
	}
	if (initialize_data(frt) == -1)
	{
		perror("Error: ");
		return (-1);
	}
	draw(frt);
	mlx_hook(frt->win, 2, 0, key_press, frt);
	mlx_hook(frt->win, 4, 0, mpress, frt);
	mlx_loop(frt->mlx);
	return (0);
}
