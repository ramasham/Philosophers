/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:08:10 by rsham             #+#    #+#             */
/*   Updated: 2024/09/01 14:59:12 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	if (!c)
		c = 0;
	while (c[i])
	{
		write(fd, &c[i], 1);
		i++;
	}
}
/*int main()
{
	int fd = 1;
	char str[] = "rama";
	ft_putstr_fd(str, fd);
}*/