/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:16:56 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/30 20:08:56 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
