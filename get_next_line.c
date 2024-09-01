/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscholz <sscholz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:46:04 by sscholz           #+#    #+#             */
/*   Updated: 2024/08/27 20:46:06 by sscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		cleanup_remainder(&remainder);
		return (NULL);
	}
	remainder = read_and_store(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(&remainder);
	if (!line && remainder && ft_strlen(remainder) > 0)
	{
		line = ft_strdup(remainder);
		cleanup_remainder(&remainder);
		return (line);
	}
	return (line);
}

char	*read_and_store(int fd, char *remainder)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (remainder);
}

char	*extract_line(char **remainder)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	if (!*remainder)
		return (NULL);
	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		line = ft_strndup(*remainder, newline_pos - *remainder + 1);
		temp = *remainder;
		*remainder = ft_strdup(newline_pos + 1);
		free(temp);
		if (ft_strlen(*remainder) == 0)
		{
			free(*remainder);
			*remainder = NULL;
		}
		return (line);
	}
	return (NULL);
}

void	cleanup_remainder(char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = (NULL);
	}
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}
