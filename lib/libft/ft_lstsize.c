/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:54 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:06:26 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

// count elements of a list

// int	main(void)
// {
// 	t_list	*cont = ft_lstnew("World\n");
// 	t_list	*cont2 = ft_lstnew("Hello Sun");
// 	t_list	*new_next = ft_lstnew("Hello");

// 	ft_lstadd_front(&cont2, cont);
// 	ft_lstadd_front(&cont, new_next);

// 	printf("%d", ft_lstsize(new_next));
// 	return (0);
// }
