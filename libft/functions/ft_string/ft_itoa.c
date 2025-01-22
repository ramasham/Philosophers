/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:42:41 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:38:57 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;

	len = get_len(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
	{
		str[--len] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
