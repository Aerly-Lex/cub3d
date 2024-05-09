/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:46:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 09:38:17 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	counter = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (counter < n)
	{
		if (ptr1[counter] != ptr2[counter])
			return (ptr1[counter] - ptr2[counter]);
		counter++;
	}
	return (0);
}

// compares byte string

// int	main(void)
// {
// 	char str1[] = "London Bridge is falling down";
// 	char str2[] = "London Bridge is falling down";
// 	size_t c = 30;

// 	printf("Result of    memcmp: %d\n", memcmp(str1, str2, c));
// 	printf("Result of ft_memcmp: %d\n", ft_memcmp(str1, str2, c));
// 	return (0);
// }
