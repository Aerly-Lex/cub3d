/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:20:13 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 10:51:11 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	size_t	counter;

	counter = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (counter < len)
	{
		str[counter] = f(counter, s[counter]);
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

//create new string from modifying string with specified function.

// char	plus_one(unsigned int counter, char c)
// {
// 	counter = +1;
// 	c = c - 1;
// 	return (c);
// }

// int	main(void)
// {
// 	char	s1[] = "J!xboob!hp!up!uif!ofyu!mjof\"";
// 	char	(*ptr)(unsigned int, char) = plus_one;

// 	printf("%s", ft_strmapi(s1, ptr));
// 	return (0);
// }
