/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:07:27 by rsham             #+#    #+#             */
/*   Updated: 2024/12/10 17:38:22 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		len_s1;
	int		len_s2;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	cat = (char *)malloc(len_s1 + len_s2 + 1);
	if (!cat)
		return (NULL);
	while (s1[i])
		cat[k++] = s1[i++];
	i = 0;
	while (s2[i])
		cat[k++] = s2[i++];
	cat[k] = '\0';
	return (cat);
}
