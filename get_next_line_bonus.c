/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:21:08 by tyuuki            #+#    #+#             */
/*   Updated: 2021/12/07 21:05:23 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		if (*temp == (char)c)
			return (temp);
		temp++;
	}
	if (*temp == (char)c)
		return (temp);
	return (NULL);
}

static char	*read_line(char *line)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

static char	*ft_write_remainder(int fd, char *buf, char *rem)
{
	int		rd;
	char	*tmp_rem;

	rd = 1;
	while (rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		if (rd == 0)
			break ;
		if (!rem)
			rem = ft_strdup("");
		buf[rd] = '\0';
		tmp_rem = rem;
		rem = ft_strjoin(rem, buf);
		free(tmp_rem);
		tmp_rem = NULL;
		if (!rem)
			return (NULL);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*remainder[FD_MAX];
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = ft_write_remainder(fd, buf, remainder[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (0);
	remainder[fd] = read_line(line);
	return (line);
}
