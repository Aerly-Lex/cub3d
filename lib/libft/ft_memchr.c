/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:17:58 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 09:37:51 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*ptr;

	counter = 0;
	ptr = (unsigned char *)s;
	while (counter < n)
	{
		if (ptr[counter] == (unsigned char)c)
			return (&ptr[counter]);
		counter++;
	}
	return (NULL);
}

// locates a byte in a byte string

// int main() {
//     char str1[50] = "London Bridge \0 is falling down.";
//     char ft_str1[50] = "London Bridge \0 is falling down.";
//     int c = '%';
//     size_t n = 300;

//     char *result1 = memchr(str1, c, n);
//     char *result2 = ft_memchr(ft_str1, c, n);

// 	printf("memchr found '%c' at position: %ld\n", c, result1 - str1);
// 	printf("ft_memchr found '%c' at position: %ld\n",c,result2 - ft_str1);

//     return 0;
// }
