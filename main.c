
#include <stddef.h>
#include "get_next_line.h"

static	void	*ft_freeforall(char **content, size_t x)
{
	size_t i;

	i = 0;
	while (i < x)
	{
		free(content[i]);
		i++;
	}
	free(content);
	return (NULL);
}

static	size_t	ft_nbr_of_split(char const *s, char c)
{
	size_t	begin;
	size_t	count;
	size_t	nbr;

	begin = 0;
	count = 0;
	nbr = 0;
	while (s[count])
	{
		while (s[count] == c && s[count])
			count++;
		begin = count;
		while (s[count] != c && s[count])
			count++;
		if (begin != count)
			nbr++;
	}
	return (nbr);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;
	size_t	i;
	size_t	begin;

	count = 0;
	i = 0;
	begin = 0;
	if (!(tab = malloc(sizeof(char*) * (ft_nbr_of_split(s, c) + 1))))
		return (0);
	while (s[count])
	{
		while (s[count] == c && s[count])
			count++;
		begin = count;
		while (s[count] != c && s[count])
			count++;
		if (begin != count)
			if (!(tab[i++] = ft_substr(s, begin, count - begin)))
				return (ft_freeforall(tab, i));
	}
	tab[i] = NULL;
	return (tab);
}


#include <stdio.h>
int main()
{
	char **str;
	int i = 0;
	str = malloc(sizeof(char*));
	//str = ft_split("bourriquot", 'u');
	str = ft_biggertab(str, 10);
	str[0] = ft_substr("yolo",0,3);
	str[1] = ft_substr("end",0,3);
	while(str[i])
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}

}
