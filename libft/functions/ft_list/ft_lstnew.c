/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:26:37 by rsham             #+#    #+#             */
/*   Updated: 2024/09/02 19:10:07 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n)
	{
		n->content = content;
		n->next = NULL;
	}
	return (n);
}
/*int main()
{
	int data = 42;
	t_list *node = ft_lstnew(&data);

	if (node)
	{
		printf("content: %d\n", *(int *)node->content);
		printf("next: %p\n", (void *)node->next);
	}
	else
		printf("failed\n");
}*/