/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 12:57:26 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/29 15:20:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_mapdel(void **map)
{
	int b;

	b = 0;
	while (map[b])
	{
		free(map[b]);
		b++;
	}
	free(map);
	return (0);
}
