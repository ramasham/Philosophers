/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:46:06 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:39:57 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n;
	int		i;
	size_t	len;

	len = ft_strlen(s);
	n = (char *)malloc(len + 1);
	if (!n)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
/*int main()
{
	char str[] = "aAjdadffj52";
	char *nstr = ft_strmapi(str, helper);
	printf("%s\n", nstr);
}*/