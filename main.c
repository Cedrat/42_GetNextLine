

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
	char *tab;
	int fd;
	int i = 1;

	tab = NULL;
	fd = open("42",O_RDONLY);
	while (i > 0)
	{

		i = get_next_line(fd, &tab);
		printf("%d\n", i);
	}
	printf("str = //------>%s//\n", tab);
	free(tab);
}
