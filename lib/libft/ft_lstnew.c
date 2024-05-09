/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:21:42 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:18:51 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (str == NULL)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}

// create new list

// int	main(void)
// {
// 	t_list	*node;
// 	char	content[] = "Hello, world!";

// 	node = ft_lstnew(content);
// 	if (node == NULL)
// 	{
// 		printf("Es gab ein Problem bei der Knotenerstellung.\n");
// 		return 1;
// 	}
// 	// Den Inhalt des Knotens ausgeben
// 	printf("Knoteninhalt: %s\n", (char*)node->content);
// 	// Prüfen, ob "next" auf NULL gesetzt ist
// 	if (node->next == NULL)
// 		printf("Der 'next'-Zeiger des Knotens zeigt auf NULL.\n");
// 	else
// 		printf("Der 'next'-Zeiger des Knotens zeigt nicht auf NULL.\n");
// 	free(node);
// return 0;
// }
