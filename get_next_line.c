#include "get_next_line.h"
#include <stdio.h>
char	*find_next_line(int fd, char *line, char *buf)
{
	size_t	i;
	int		f;

	i = 0;
	printf("\n3\n");
	while (buf[i] != '\n' || buf[i] != '\0')
		i++;
	printf("5");
	line = (char *)malloc(i * sizeof(char));
	if (!line)
		return (NULL);
	printf("\n4\n");
	while (i >= 0)
	{
		line[i] = buf[i];
		i--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			f;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	save = NULL;
	printf("\n1\n");
	/*if (!*save)
	{
		printf("\n5\n");
		read(fd, save, BUFFER_SIZE);
		printf("\n4\n");
		line = find_next_line(fd, line, save);
	}*/
	f = read(fd, save, BUFFER_SIZE);
	if (f < 0)
	{
		printf("\ninvalid fd\n");
		return (NULL);
	}
	line = find_next_line(fd, line, save);
	printf("\n2\n");
	return (line);
}

int	main(void)
{
	get_next_line(156);
	return 0;
}

