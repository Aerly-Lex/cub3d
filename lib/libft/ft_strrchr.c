/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:07:09 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/11 10:16:01 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

// locates a char on LAST occurence in a string

// int	main()
// {
// 	char str1[50] = "London Bri\0dge is falling \0down";
// 	char c = '\0';

// 	printf("Result of    strrchr: %s\n", strrchr(str1, c));
// 	printf("Result of ft_strrchr: %s\n", ft_strrchr(str1, c));
// 	return (0);
// }
