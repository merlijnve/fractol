/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:34:36 by jboer          #+#    #+#                */
/*   Updated: 2019/09/29 15:20:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	n;
	char			*strb;

	strb = b;
	n = (unsigned char)c;
	while (len > 0)
	{
		*strb = n;
		strb++;
		len--;
	}
	return (b);
}
