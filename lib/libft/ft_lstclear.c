/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:54:57 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:05:14 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

// delete everything from lst(starting point) till end

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
// 	ft_lstclear(&head, del_function);
// 	printf("\n\nAfter the Deletion:\n");
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%s", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
