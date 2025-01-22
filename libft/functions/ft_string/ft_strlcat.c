/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:03:28 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:39:36 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = 0;
	d_len = 0;
	while (src[s_len])
	{
		s_len++;
	}
	while (dst[d_len] && d_len < size)
	{
		d_len++;
	}
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	while (i < (size - d_len - 1) && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
