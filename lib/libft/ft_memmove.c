/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:49:54 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/10 16:07:40 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			counter;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	counter = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ptr_dst > ptr_src)
	{
		while (len-- > 0)
			ptr_dst[len] = ptr_src[len];
	}
	else
	{
		while (counter < len)
		{
			ptr_dst[counter] = ptr_src[counter];
			counter++;
		}
	}
	return (dst);
}

// int	main()
// {
// 	char str1[50] = "London Bridge is falling down.";
// 	char ft_str1[50] = "London Bridge is falling down.";
// 	char str2[50] = "Build it up with Wood and stone!";
// 	printf("Before   memmove: %s\n", str1);

// 	memmove(str1, str2, 20);
// 	ft_memmove(ft_str1, str2, 20);
// 	printf("After    memmove: %s\n", str1);
// 	printf("After ft_memmove: %s\n", ft_str1);
// 	return (0);
// }
