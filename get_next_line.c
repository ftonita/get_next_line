#include "get_next_line.h"

char	*ft_remind(char **tail)
{
	char		*l;
	char		*new_line;
	char		*temp;

	if (*tail != NULL)
	{
		if (ft_strchr(*tail, '\n'))
		{
			new_line = ft_strchr(*tail, '\n');
			temp = ft_strdup(new_line + 1);
			*(new_line + 1) = '\0';
			l = ft_strdup(*tail);
			free(*tail);
			*tail = temp;
		}
		else
		{
			l = *tail;
			*tail = NULL;
		}
	}
	else
		l = ft_strdup("");
	return (l);
}

char	*ft_reader(int fd, char *line, char **tail, int rd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	char	*pn;

	while (rd > 0 && !ft_strchr(line, '\n') && !(*tail))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			pn = ft_strchr(buffer, '\n');
			*tail = ft_strdup(pn + 1);
			*(pn + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;
	char		buf[1];
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	rd = 1;
	line = ft_remind(&tail);
	line = ft_reader(fd, line, &tail, rd);
	return (line);
}