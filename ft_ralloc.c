/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ralloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 15:55:06 by lnoaille          #+#    #+#             */
/*   Updated: 2020/05/17 16:03:11 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_biggertab(char **tab, unsigned int newsize)
{
	size_t x;
	char **newtab;

	x = 0;
	if (!(*newtab = malloc(sizeof(char**) * (newsize + 1))))
		return (NULL);
	while(tab[x])
	{
		newtab[x] = tab[x];
		free(tab[x])
		x++;
	}
	newtab[x] = NULL;
	free(tab);
	return (newtab);
}
