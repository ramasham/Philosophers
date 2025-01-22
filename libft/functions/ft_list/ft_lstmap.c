/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:41:02 by rsham             #+#    #+#             */
/*   Updated: 2025/01/08 15:24:35 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*ret;
	void	*new_content;

	ret = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		n = ft_lstnew(new_content);
		if (!n)
		{
			ft_lstclear(&ret, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&ret, n);
		lst = lst->next;
	}
	return (ret);
}
