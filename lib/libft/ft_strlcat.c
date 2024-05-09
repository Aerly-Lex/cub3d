/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1023/10/07 12:51:35 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:10:31 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	dst_len;
	size_t	src_len;

	counter = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[counter] != '\0' && (dst_len + counter) < size - 1)
	{
		dst[dst_len + counter] = src[counter];
		counter++;
	}
	dst[dst_len + counter] = '\0';
	if (dst_len < size)
		return (dst_len + src_len);
	return (src_len + size);
}

// appends source-string to destination-string till size or end of src-len

// int	main()
// {
// 	char str1[50] = "pqrs";
// 	char ft_str1[50] = "pqrs";
// 	char str2[50] = "abcdefghi";
// 	size_t result, ft_result;
// 	printf("Before   strlcat: %s\n", str1);

// 	strlcat(str1, str2, 10);
// 	ft_strlcat(ft_str1, str2, 10);
// 	result = strlcat(str1, str2, 10);
// 	ft_result = ft_strlcat(ft_str1, str2, 10);
// 	printf("After    strlcat: %lu\n", result);
// 	printf("After    strlcat: %s\n", str1);
// 	printf("After ft_strlcat: %lu\n", ft_result);
// 	printf("After ft_strlcat: %s\n", ft_str1);
// 	return (0);
// }
