/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:00:23 by lnoaille          #+#    #+#             */
/*   Updated: 2020/05/19 17:31:58 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 20
#include <stdio.h>

int get_line(int fd, char **temp)
{
	size_t end;
	char *str;

	while (!(ft_strchr(*temp, '\n')))
	{
		if (!(str = malloc(sizeof(char)* BUFFER_SIZE + 1)))
			return (-1);
		end = read(fd, str, BUFFER_SIZE); // element central ?
		str[end] = '\0';
		*temp = ft_strjoin(*temp, str);
		if (end == 0)
			return (0);
	}
	return (1);
}

int	ft_read_until_next_line(int fd, char **str)
{
	char *str1;
	char *str2;
	static char *temp;
	size_t x;
	int return_value;

	if (!temp)
		if (!(temp = malloc(sizeof(char)* BUFFER_SIZE + 1)))
		{
			temp = NULL;
			return (-1);
		}
	return_value = get_line(fd, &temp);
	x = 0;
	while (temp[x] != '\n')
		x++;
	if (!(str2 = ft_substr(temp, 0, x + 1)))
		return (-1);
	if (!(str1 = ft_substr(temp, x + 1, ft_strlen(temp))))
		return (-1);
	free(temp);
	if (!(temp = ft_substr(str1, 0, ft_strlen(str1))))
	 	return (-1);// perte ?
	free(str1);
	if (!(*str = ft_strjoin(*str, str2)))
		return (-1); //perte *str ?
	return (return_value);
}



int	get_next_line(int fd, char **line)
{
	return (ft_read_until_next_line(fd, *(&line)));
}


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *tab;
	int fd;

	tab = malloc(sizeof(char*));
	fd = open("42",O_RDONLY);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	get_next_line(fd, &tab);
	printf("str = //------>%s//\n", tab);
	free(tab);
}
