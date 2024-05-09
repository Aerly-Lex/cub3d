/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:19:44 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 09:39:34 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	counter = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (counter < n)
	{
		ptr_dst[counter] = ptr_src[counter];
		counter++;
	}
	return (dst);
}

// int main()
// {
//     char str1[50] = "GeeksForGeeks IS for programming geeks.";
// 	char ft_str1[50] = "GeeksForGeeks IS for programming geeks.";
// 	char str2[50] = "This is a real program and not some Bull";
//     printf("\nBefore memcpy(): %s\n", str1);

//     memcpy(str1, str2, 15);
// 	ft_memcpy(ft_str1, str2, 15);

//     printf("After memcpy():  %s\n", str1);
// 	printf("After ft_memcpy():  %s\n", ft_str1);
//     return 0;
// }
