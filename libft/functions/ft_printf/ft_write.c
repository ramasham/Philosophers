/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:41:53 by rsham             #+#    #+#             */
/*   Updated: 2024/12/08 13:59:36 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_print_id(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_print_char('-');
		i = -i;
	}
	if (i >= 10)
		ft_print_id(i / 10);
	ft_print_char((i % 10) + '0');
}

int	ft_print_str(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (c)
	{
		while (c[i])
		{
			write(1, &c[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_print_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_print_uns(n / 10);
	i += ft_print_char((n % 10) + '0');
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
