/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:53:30 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:13:00 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// locates a char on FIRST occurence in a string

// #include <string.h>
// int	main()
// {
// 	char str1[50] = "London Bridge is falling down";
// 	char c = 'B';

// 	printf("Result of    strchr: %s\n", strchr(str1, c));
// 	printf("Result of ft_strchr: %s\n", ft_strchr(str1, c));
// 	return (0);
// }
