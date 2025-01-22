/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:03:38 by rsham             #+#    #+#             */
/*   Updated: 2024/09/08 18:51:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n)
	{
		ft_print_char('0');
		ft_print_char('x');
		i += ft_print_hex(n);
		return (i + 2);
	}
	return (ft_print_str("(nil)"));
}
