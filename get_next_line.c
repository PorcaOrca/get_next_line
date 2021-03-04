/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:49:51 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/26 10:57:59 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_read_line(char **end_line, char **buffer, int fd, int b_size)
{
	char	*buf;
	int		read_ret;
	char	*temp;

	read_ret = b_size;
	while (!(*end_line = ft_strchr(*buffer, '\n')) && read_ret == b_size)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (b_size + 1))))
			return (-1);
		if ((read_ret = read(fd, buf, b_size)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[read_ret] = '\0';
		if (!(temp = ft_strjoin(*buffer, buf)))
		{
			free(buf);
			return (-1);
		}
		free(buf);
		free(*buffer);
		*buffer = temp;
	}
	return (read_ret);
}

int		ft_returner(char **end_line, char **buffer)
{
	char	*temp;

	if (*end_line)
	{
		if (!(temp = ft_strdup(*end_line + 1)))
		{
			free(*buffer);
			return (-1);
		}
		free(*buffer);
		*buffer = temp;
		return (1);
	}
	free(*buffer);
	*buffer = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer[256];
	char			*end_line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	end_line = NULL;
	if (!buffer[fd])
	{
		if (!(buffer[fd] = ft_strdup("")))
			return (-1);
	}
	if ((ft_read_line(&end_line, &buffer[fd], fd, BUFFER_SIZE)) < 0)
	{
		free(buffer[fd]);
		return (-1);
	}
	if (end_line)
		*end_line = '\0';
	if (!(*line = ft_strdup(buffer[fd])))
	{
		free(buffer[fd]);
		return (-1);
	}
	return (ft_returner(&end_line, &buffer[fd]));
}
