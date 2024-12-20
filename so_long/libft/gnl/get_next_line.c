/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smurgia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:52:44 by smurgia           #+#    #+#             */
/*   Updated: 2024/12/04 17:52:46 by smurgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	freeptr(char **p)
{
	free(*p);
	*p = NULL;
}

static char	*extractor(char **statbuff, char **line)
{
	char	*nextsbuff;
	int		i;

	i = 0;
	nextsbuff = NULL;
	while (*(*statbuff + i) != '\n' && *(*statbuff + i) != '\0')
		i++;
	if (*(*statbuff + i) == '\n')
	{
		i++;
		*line = ft_substr(*statbuff, 0, i);
		nextsbuff = ft_strdup(*statbuff + i);
	}
	else
		*line = ft_strdup(*statbuff);
	freeptr(statbuff);
	return (nextsbuff);
}

static int	getline(int fd, char **buffer, char **statbuff, char **line)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(*statbuff, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temp = *statbuff;
		*statbuff = ft_strjoin(temp, *buffer);
		free(temp);
	}
	freeptr(buffer);
	*statbuff = extractor(statbuff, line);
	if (!(**line))
		freeptr(line);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*statbuff;
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!statbuff)
		statbuff = ft_strdup("");
	if (!getline(fd, &buffer, &statbuff, &line) && !line)
		return (NULL);
	return (line);
}
