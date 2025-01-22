/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:52:31 by rsham             #+#    #+#             */
/*   Updated: 2025/01/08 15:26:12 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (0);
	if (!c)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *tmp, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!tmp)
	{
		tmp = (char *)malloc(1);
		tmp[0] = '\0';
	}
	if (!tmp || !buff)
		return (NULL);
	str = malloc((ft_strlen(tmp) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (tmp)
		while (tmp[++i])
			str[i] = tmp[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(tmp);
	return (str);
}
