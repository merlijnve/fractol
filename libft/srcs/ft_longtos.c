/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longtos.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:38:16 by jboer          #+#    #+#                */
/*   Updated: 2019/09/29 15:20:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_longtos(char *strn, int intlen, int i, long long int n)
{
	i = intlen + i;
	while (intlen > 0)
	{
		i--;
		strn[i] = (n % (long long)10) + '0';
		n = n / (long long)10;
		intlen--;
	}
	return (strn);
}
