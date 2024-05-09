/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:35:20 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/18 09:49:18 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_ptr;
	void	*tmp;

	new_head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new_ptr = ft_lstnew(tmp);
		if (new_ptr == NULL)
		{
			free(tmp);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_ptr);
		lst = lst->next;
	}
	return (new_head);
}

// apply function to content of all list and put those in a new list
