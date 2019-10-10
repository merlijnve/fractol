/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ullintlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 13:19:14 by jboer          #+#    #+#                */
/*   Updated: 2019/09/29 15:20:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_ullintlen(unsigned long long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= (unsigned long long)1)
	{
		n = n / (unsigned long long)10;
		len++;
	}
	return (len);
}
