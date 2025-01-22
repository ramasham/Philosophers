/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:56:22 by rsham             #+#    #+#             */
/*   Updated: 2025/01/08 15:23:19 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	tmp_lst = *lst;
	while (tmp_lst)
	{
		next_node = tmp_lst->next;
		ft_lstdelone(tmp_lst, del);
		tmp_lst = next_node;
	}
	*lst = NULL;
}
