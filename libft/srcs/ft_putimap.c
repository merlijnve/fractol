/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putimap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 17:21:53 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/29 15:20:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putimap(int **ar)
{
	int i;
	int flag;
	int	j;

	j = 0;
	flag = 0;
	i = 0;
	while (ar[i])
	{
		while (ar[i][j])
		{
			ft_putnbr(ar[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
