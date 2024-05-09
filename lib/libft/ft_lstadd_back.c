/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:05:20 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:05:13 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

// add new element at end of list

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*cont3 = ft_lstnew("Hello Sun");
// 	t_list	*cont2 = ft_lstnew("World\n");
// 	t_list	*cont1 = ft_lstnew("Hello ");

// 	ft_lstadd_back(&head, cont1);
// 	ft_lstadd_back(&head, cont2);
// 	ft_lstadd_back(&head, cont3);

// 	while (head != NULL)
// 	{
// 		printf("%s", (char *)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }
