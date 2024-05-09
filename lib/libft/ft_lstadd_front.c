/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:56:02 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 17:42:21 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// add new lement at the beginning of list

// int	main(void)
// {
// 	t_list	*cont = ft_lstnew("World\n");
// 	t_list	*cont2 = ft_lstnew("Hello Sun!");
// 	t_list	*new_next = ft_lstnew("Hello");

// 	ft_lstadd_front(&cont2, cont);
// 	ft_lstadd_front(&cont, new_next);

// 	while (cont)
// 	{
// 		printf("%s", (char *)cont->content);
// 		cont = cont ->next;
// 	}
// 	return (0);
// }
