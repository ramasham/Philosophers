/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:35:52 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:36:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*n;
	int		beg;
	int		len;
	int		end;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1) - 1;
	while (end > beg && ft_strchr(set, s1[end]))
		end--;
	len = end - beg + 1;
	n = (char *)malloc(len + 1);
	if (!n)
		return (NULL);
	ft_memcpy(n, s1 + beg, len);
	n[len] = '\0';
	return (n);
}
