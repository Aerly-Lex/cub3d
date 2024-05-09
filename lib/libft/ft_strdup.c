/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:20:08 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:28:59 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;
	size_t	counter;

	counter = 0;
	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[counter] != '\0')
	{
		ptr[counter] = s1[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}

// creates with malloc a new string size of s1 and returns the starting point

// int	main(void)
// {
// 	const char	s1[] = "London Bridge is falling down.";
// 	const char	s2[] = "London Bridge is falling down.";

// 	printf("After    strdup: %s\n", strdup(s1));
// 	printf("After ft_strdup: %s\n", ft_strdup(s2));
// 	return (0);
// }
