/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:21:56 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/27 08:39:58 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strdup(const char *str);
int				ft_read_line(char **end_line, char **buffer,
					int fd, int b_size);
int				ft_returner(char **end_line, char **buffer);

#endif
