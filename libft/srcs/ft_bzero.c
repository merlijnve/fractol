/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:56:42 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/30 20:16:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*l;

	i = 0;
	l = (char *)s;
	while (n > 0)
	{
		l[i] = '\0';
		i++;
		n--;
	}
}
