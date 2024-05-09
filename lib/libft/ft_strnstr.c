/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:38:15 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/09 13:38:00 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	needle_counter;

	counter = 0;
	if (needle[counter] == '\0')
		return ((char *)haystack);
	while (haystack[counter] != '\0' && counter < len)
	{
		needle_counter = 0;
		while (haystack[counter + needle_counter] == needle[needle_counter]
			&& (counter + needle_counter) < len)
		{
			if (needle[needle_counter +1] == '\0')
				return ((char *)&haystack[counter]);
			needle_counter++;
		}
		counter++;
	}
	return (NULL);
}

// int	main()
// {
// 	char str2[] = "London Bridge is falling down falling down My fair Lady";
// 	char str1[] = "London Bridge is falling down falling down, My fair Lady";
// 	char needle[] = "fair";
// 	int c = 56;

// 	printf("Result of    strnstr: %s\n", strnstr(str1, needle, c));
// 	printf("Result of ft_strnstr: %s\n", ft_strnstr(str2, needle, c));
// 	return (0);
// }
