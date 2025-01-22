/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:31:22 by rsham             #+#    #+#             */
/*   Updated: 2024/09/08 19:50:54 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_numlen(int n)
{
	ft_print_id(n);
	return (get_len(n));
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
