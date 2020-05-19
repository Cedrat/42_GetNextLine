/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:00:21 by lnoaille          #+#    #+#             */
/*   Updated: 2020/05/19 17:31:48 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t pos;

	pos = 0;
	while (s[pos])
		pos++;
	return (pos);
}

void ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s_join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(s_join = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (0);
	len_s1 = 0;
	while (s1[len_s1])
	{
		s_join[len_s1] = s1[len_s1];
		len_s1++;
	}
	len_s2 = 0;
	while (s2[len_s2])
	{
		s_join[len_s1 + len_s2] = s2[len_s2];
		len_s2++;
	}
	s_join[len_s1 + len_s2] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (s_join);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*copy;

	copy = (unsigned char*)s;
	count = 0;
	while (count < n)
	{
		if (copy[count] == (unsigned char)c)
			return (&copy[count]);
		count++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subcopy;
	size_t	count;

	count = 0;
	if (!(subcopy = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	while (count < len)
	{
		subcopy[count] = s[count + start];
		count++;
	}
	subcopy[count] = '\0';
	return (subcopy);
}

char	*ft_biggerstr(char *tab, size_t newsize)
{
	char *newstr;

	if (!(newstr = malloc(sizeof(char *) * (newsize + 1))))
		return (NULL);

	newstr = ft_substr(tab, 0, ft_strlen(tab));
	newstr[ft_strlen(tab)] = '\0';
	free(tab);
	return (newstr);
}

int	ft_strchr(const char *s, int c)
{
	int pos;

	pos = 0;
	if (s == NULL)
		return (0);
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
			return (1);
		pos++;
	}
	if (s[pos] == c)
		return (1);
	else
		return (0);
}
