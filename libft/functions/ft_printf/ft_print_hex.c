/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:02:10 by rsham             #+#    #+#             */
/*   Updated: 2024/12/07 18:20:00 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_print_hexu(unsigned int n)
// {
// 	char hex[] = "0123456789abcdef";
// 	if (n>= 16)
// 		print_hex(n / 16);
// 	write(1, &hex[n % 16], 1);
// }
int	ft_print_hexu(unsigned int n)
{
	char	hex[16];
	int		i;
	int		l;
	char	h[17];

	ft_strcpy(h, "0123456789ABCDEF");
	i = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	while (n > 0)
	{
		hex[i] = h[n % 16];
		n /= 16;
		i++;
	}
	hex[i] = '\0';
	l = i;
	while (--l >= 0)
		ft_print_char(hex[l]);
	return (i);
}

int	ft_print_hexl(unsigned int n)
{
	char	hex[16];
	int		i;
	int		l;
	char	h[17];

	ft_strcpy(h, "0123456789abcdef");
	i = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	while (n > 0)
	{
		hex[i] = h[n % 16];
		n /= 16;
		i++;
	}
	hex[i] = '\0';
	l = i;
	while (--l >= 0)
		ft_print_char(hex[l]);
	return (i);
}

int	ft_print_hex(size_t n)
{
	char	hex[16];
	int		i;
	int		l;
	char	h[17];

	ft_strcpy(h, "0123456789abcdef");
	i = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	while (n > 0)
	{
		hex[i] = h[n % 16];
		n /= 16;
		i++;
	}
	hex[i] = '\0';
	l = i;
	while (--l >= 0)
		ft_print_char(hex[l]);
	return (i);
}
