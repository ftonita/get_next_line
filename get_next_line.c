/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 03:19:08 by ftonita           #+#    #+#             */
/*   Updated: 2021/12/24 03:19:10 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*ft_end(char *line, char *tail)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	i++;
	tmp = i;
	while (line[i])
	{
		tail[j] = line[i++];
		j++;
	}
	line[tmp] = '\0';
	while (j < BUFFER_SIZE)
		tail[j++] = '\0';
	return (line);
}

char	*ft_reader(int fd, char *line, char *tail)
{
	if (line == NULL)
		return (NULL);

	while (ft_strchr(line, '\n') == 0 )
	{
		if (read(fd, tail, BUFFER_SIZE) == 0)
		{

			
		printf("\n line: %s\n", line);
		printf("\n tail: %s\n", tail);
		
			line = ft_end(line, tail);
			return (line);
		}
		line = ft_strjoin(line, tail);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	tail[BUFFER_SIZE];
	char		*line;

	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (read(fd, tail, 0) < 0 || BUFFER_SIZE < 0)
	{
		free(line);
		return (NULL);
	}
	line = ft_strjoin(line, tail);
	if (!ft_strlen(line))
	{
		if (read(fd, tail, BUFFER_SIZE) == 0)
		{
			free(line);
			return (NULL);
		}
		else
			line = ft_strjoin(line, tail);
	}
	line = ft_reader(fd, line, tail);
	line = ft_end(line, tail);
	return (line);
}
