/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:22:01 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/26 10:58:48 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *str, int c)
{
	char	temp;
	size_t	i;
	int		is_eq;

	i = 0;
	temp = (char)c;
	while (str[i])
	{
		is_eq = str[i] - temp;
		if (is_eq == 0)
			return ((char *)&str[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (NULL);
}

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	str_lenght;

	i_dest = 0;
	i_src = 0;
	str_lenght = ft_strlen(src);
	while (dest[i_dest])
		i_dest++;
	if (size == 0)
		return (str_lenght);
	if (size <= i_dest)
		return (str_lenght + size);
	while (size && src[i_src] && i_dest + 1 < size)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
	return (i_dest - i_src + str_lenght);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char			*ft_strjoin(char const *str1, char const *str2)
{
	char	*str_out;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_out = (char *)malloc(sizeof(char) * i);
	if (str_out == NULL)
		return (NULL);
	ft_strlcpy(str_out, str1, i);
	ft_strlcat(str_out, str2, i);
	return (str_out);
}

char			*ft_strdup(const char *str)
{
	char	*dup;
	int		size;

	size = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, size + 1);
	return (dup);
}
