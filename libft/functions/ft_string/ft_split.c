/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:08:09 by rsham             #+#    #+#             */
/*   Updated: 2024/09/04 19:31:33 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

int	check_malloc(char **result, int i)
{
	if (!result[i])
	{
		while (i-- > 0)
			free(result[i]);
		free(result);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			i;
	const char	*start;

	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*start && *start != c)
				start++;
			result[i++] = word_dup(s, (start - s));
			if (!check_malloc(result, i - 1))
				return (NULL);
			s = start;
		}
	}
	result[i] = NULL;
	return (result);
}
/*int	main(void)
{
	char str[] = "Hello,,world, this,is,a,test";
	char delimiter = ',';
	char **result;
	int i;

	// Split the string
	result = ft_split(str, delimiter);

	// Check if the split operation was successful
	if (!result)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return (1); // Exit with error code
	}

	// Print the result
	for (i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i, result[i]);
	}

	// Free the allocated memory
	for (i = 0; result[i] != NULL; i++)
	{
		free(result[i]);
	}
	free(result);

	return (0); // Exit successfully
}*/