#include "get_next_line.h"

char	*find_next_line(int fd)
{
	void	*buf;
	char	*line;
	size_t	i;
	int		f;

	i = 0;
	buf = NULL;
	f = read(fd, buf, BUFFER_SIZE);
	if (ft_strchr((const char *)buf, '\n'))
		;
	line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	(void) save;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!*save)
		line = find_next_line(fd);
	return (line);
}

int	main(void)
{
	get_next_line(1);
	return 0;
}

