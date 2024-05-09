/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:21:56 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:17:38 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (s1[count] == s2[count] && count < n
		&& s1[count] && s2[count])
		count++;
	if (count == n)
		return (0);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

// int	main()
// {
// 	char str1[] = "London Bridge is falling dowa";
// 	char str2[] = "London Bridge is falling down";
// 	int c = 29;

// 	printf("Result of    strncmp: %d\n", strncmp(str1, str2, c));
// 	printf("Result of ft_strncmp: %d\n", ft_strncmp(str1, str2, c));
// 	return (0);
// }
