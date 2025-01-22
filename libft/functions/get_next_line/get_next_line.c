/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:51:39 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 19:19:48 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_tmp(int fd, char *tmp)
{
	char	*buff;
	ssize_t	rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(tmp);
		return (NULL);
	}
	rd_bytes = 1;
	while (!ft_strchr_gnl(tmp, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(tmp);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		tmp = ft_strjoin_gnl(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*ft_get_line(char *tmp)
{
	int		i;
	char	*str;

	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_tmp(char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	str = malloc(ft_strlen(tmp) - i + 1);
	if (!str)
	{
		free(tmp);
		return (NULL);
	}
	i++;
	j = 0;
	while (tmp[i])
		str[j++] = tmp[i++];
	str[j] = '\0';
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_tmp(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_get_line(tmp);
	tmp = ft_new_tmp(tmp);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
