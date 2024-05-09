/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:06:45 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:10:57 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	len;

	counter = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (counter < size - 1 && src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (len);
}

// copies source-string to destination-string till size or \0 is reached

// int	main()
// {
// 	char str1[50] = "London Bridge is down.";
// 	char ft_str1[50] = "London Bridge is down.";
// 	char str2[50] = "Build it up with Wood and stone! Wood and Stone";
// 	printf("Before   strlcpy: %s\n", str1);

// 	strlcpy(str1, str2, 30);
// 	ft_strlcpy(ft_str1, str2, 30);
// 	printf("After    strlcpy: %s\n", str1);
// 	printf("After ft_strlcpy: %s\n", ft_str1);
// 	return (0);
// }
