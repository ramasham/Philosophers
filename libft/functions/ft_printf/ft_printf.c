/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:32:08 by rsham             #+#    #+#             */
/*   Updated: 2024/09/09 13:13:20 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char c, va_list format)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(format, int));
	else if (c == 's')
		count = ft_print_str(va_arg(format, char *));
	else if (c == 'd' || c == 'i')
		count = ft_numlen(va_arg(format, int));
	else if (c == 'p')
		count = ft_print_ptr(va_arg(format, unsigned long));
	else if (c == 'x')
		count = ft_print_hexl(va_arg(format, unsigned int));
	else if (c == 'X')
		count = ft_print_hexu(va_arg(format, unsigned int));
	else if (c == 'u')
		count = ft_print_uns(va_arg(format, unsigned int));
	else if (c == '%')
		count = ft_printpercent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		i;
	int		ret;

	va_start(args, str);
	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			c += ft_print_char(str[i++]);
		else
		{
			ret = ft_format(str[i + 1], args);
			c += ret;
			i += 2;
		}
	}
	va_end(args);
	return (c);
}
