/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 16:17:37 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/27 12:37:22 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line_nr_copy(char *str, char *trc)
{
	size_t	len;
	char	*newl;
	char	*line;

	len = ft_strdlen(str, '\n');
	newl = ft_strchr(str, '\n');
	if (newl == NULL)
		newl = str;
	else
	{
		newl++;
		ft_strclr(trc);
		ft_strncpy(trc, newl, ft_strlen(newl));
	}
	line = ft_strnew(len);
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, str, len);
	if (str[0] == '\n')
		ft_strclr(line);
	return (line);
}

char	*ft_gnl_catch_input(const int fd, char *str, char *trc, int *ret)
{
	char		*temp;
	char		buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	temp = ft_strjoin(str, trc);
	ft_strdel(&str);
	str = temp;
	ft_strclr(trc);
	ft_strclr(buf);
	if (ft_strchr(str, '\n') != NULL)
		return (str);
	while (*ret != 0)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		if (*ret == -1)
			return (NULL);
		temp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = temp;
		ft_strclr(buf);
		if (*ret < BUFF_SIZE || ft_strchr(str, -1) != NULL || \
		ft_lncount(str) > 0)
			break ;
	}
	return (str);
}

void	ft_free_stuff(char *str, int *ret)
{
	ft_strdel(&str);
	free((void *)ret);
}

int		get_next_line(const int fd, char **line)
{
	static char *trc;
	char		*str;
	int			*ret;

	if (fd == -1)
		return (-1);
	ret = (int *)malloc(sizeof(int));
	*ret = -1;
	if (trc == NULL)
		trc = ft_strnew(BUFF_SIZE);
	str = ft_strnew(BUFF_SIZE);
	if (str == NULL || trc == NULL)
		return (-1);
	str = ft_gnl_catch_input(fd, str, trc, ret);
	if (str == NULL)
		return (-1);
	if (*ret == 0 && ft_strlen(str) == 0)
	{
		ft_free_stuff(str, ret);
		return (0);
	}
	*line = ft_line_nr_copy(str, trc);
	ft_free_stuff(str, ret);
	return (1);
}
