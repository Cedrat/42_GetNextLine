/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:00:27 by lnoaille          #+#    #+#             */
/*   Updated: 2020/05/19 15:48:10 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*ft_biggerstr(char *tab, size_t newsize);
int		ft_strchr(const char *s, int c);

# endif
