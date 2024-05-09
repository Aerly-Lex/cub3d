/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:45:26 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:05:29 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// find the last element of the list

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*last_node = NULL;
// 	t_list	*cont1 = ft_lstnew("Hello Sun");
// 	t_list	*cont2 = ft_lstnew("World\n");
// 	t_list	*new_next = ft_lstnew("Hello");

// 	ft_lstadd_front(&head, cont1);
// 	ft_lstadd_front(&head, cont2);
// 	ft_lstadd_front(&head, new_next);

// 	last_node = ft_lstlast(head);
// 	printf("%s", (char *)last_node->content);
// 	return (0);
// }
