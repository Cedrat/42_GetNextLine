/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:00:23 by lnoaille          #+#    #+#             */
/*   Updated: 2020/05/20 21:24:48 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	get_line(int fd, char **temp)
{
	size_t	end;
	char	*str;

	if (!*temp)
	{
		if (!(*temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		*temp[0] = '\0';
	}
	while (!(ft_strchr(*temp, '\n')))
	{
		if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		if (!(end = read(fd, str, BUFFER_SIZE)) && ft_strlen(*temp) == 0)
		{
			free(str);
			free(*temp);
			return (0);
		}
		str[end] = '\0';
		*temp = ft_strjoin_f(*temp, str);
		if (end != BUFFER_SIZE)
			break ;
	}
	return (1);
}

int append_line(int fd, char **line)
{
	char		*str1;
	char		*str2;
	static char	*temp;
	size_t		x;
	int			return_value;

	if (!(return_value = get_line(fd, &temp)))
		return (return_value);
	x = 0;
	while (temp[x] != '\n' && temp[x])
		x++;
	if (!(str2 = ft_substr(temp, 0, x + 1)))
		return (-1);
	if (!(str1 = ft_substr(temp, x + 1, ft_strlen(temp) - (x))))
		return (-1);
	free(temp);
	if (!(temp = ft_substr(str1, 0, ft_strlen(str1))))
		return (-1);
	if (!(return_value = ft_strchr(str2, '\n')))
		free(temp);
	free(str1);
	if (!(*line = ft_strjoin_f(*line, str2)))
		return (-1);
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	if (!(*line))
	{
		*line = malloc(sizeof(char));
		*line[0] = '\0';
	}
	return (append_line(fd, &(*line)));
}
