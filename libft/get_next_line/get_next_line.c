/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 07:52:28 by nayala            #+#    #+#             */
/*   Updated: 2025-04-24 07:52:28 by nayala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//aux ft for read buffer (to many lines)
static char	*read_loop(int fd, char *buffer, char *buf)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (!ft_gnl_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buf[bytes] = '\0';
		tmp = buffer;
		buffer = ft_gnl_strjoin(buffer, buf);
		free(tmp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

//Read into the fd until we find \n || end of the file || BUFFER_SIZE
//Buf saves the bytes of fd to later concadenate with the previous buffer
static char	*read_buffer(int fd, char *buffer)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE +1);
	if (!buf)
		return (NULL);
	if (!buffer)
		buffer = ft_gnl_strdup("");
	if (!buffer)
		return (free(buf), NULL);
	buffer = read_loop(fd, buffer, buf);
	if (!buffer)
		return (free(buf), NULL);
	free(buf);
	return (buffer);
}

//Extract a line from the buffer including \n if there is one
static char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_gnl_substr(buffer, 0, i + 1);
	else
		line = ft_gnl_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

//Save what remains in the buffer after extracting the line
static char	*save_rest(char *buffer)
{
	size_t	i;
	char	*rest;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	rest = ft_gnl_strdup(buffer + i + 1);
	free(buffer);
	if (!rest || rest[0] == '\0')
		return (free(rest), NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = save_rest(buffer);
	return (line);
}
