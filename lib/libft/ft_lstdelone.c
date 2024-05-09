/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:25:33 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:05:15 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free (lst);
}

// delete element from list

// void	del_function(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *temp = NULL;
// 	t_list *cont3 = ft_lstnew(ft_strdup("Hello Sun"));
// 	t_list *cont2 = ft_lstnew(ft_strdup("World\n"));
// 	t_list *cont1 = ft_lstnew(ft_strdup("Hello "));

// 	ft_lstadd_back(&head, cont1);
// 	ft_lstadd_back(&head, cont2);
// 	ft_lstadd_back(&head, cont3);

// 	printf("Before the Deletion:\n");
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%s", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstdelone(cont2, del_function);
// 	printf("\n\nAfter the Deletion:\n");
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%s", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
