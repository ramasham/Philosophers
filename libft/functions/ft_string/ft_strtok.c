/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:48:52 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:40:29 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next;
	char		*start;

	next = NULL;
	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	start = next;
	while (*start && ft_strchr(delim, *start))
		start++;
	if (*start == '\0')
		return (NULL);
	next = start;
	while (next && !ft_strchr(delim, *next))
		next++;
	if (*next)
	{
		next = '\0';
		next++;
	}
	return (start);
}
