/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:01:18 by rsham             #+#    #+#             */
/*   Updated: 2024/09/01 15:05:56 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *c, int fd)
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
	write(fd, "\n", 1);
}
/*int main()
{
	int fd = 1;
	char str[] = "rama";
	ft_putendl_fd(str, fd);
}*/