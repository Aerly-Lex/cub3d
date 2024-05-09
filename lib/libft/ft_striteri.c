/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:49:58 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:17:07 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	counter;

	counter = 0;
	len = ft_strlen(s);
	while (counter < len)
	{
		f(counter, &s[counter]);
		counter++;
	}
}

// iterate the pointer-function over every char of string

// static void	plus_one(unsigned int counter, char *c)
// {
// 	counter = +1;
// 	*c = *c - 1;
// }

// int	main(void)
// {
// 	char	s1[] = "J!xboob!hp!up!uif!ofyu!mjof\"";
// 	void	(*ptr)(unsigned int, char*) = plus_one;

// 	ft_striteri(s1, ptr);
// 	printf("%s", s1);
// 	return (0);
// }
