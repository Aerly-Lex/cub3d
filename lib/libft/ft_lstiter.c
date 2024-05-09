/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:18:14 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:22:23 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// apply function to every element of list

// void	ft_toupper(void *content)
// {
// 	char	*str = (char *)content;
// 	while (*content != '\0')
// 	{
// 		if (*str >= 'a' && *str <= 'z')
// 			*str -= 32;
// 		str++;
// 	}
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

// 	printf("Before the Changes:\n");
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%s", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstiter(head, ft_toupper);
// 	printf("\n\nAfter the Changes:\n");
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%s", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	return (0);
// }
