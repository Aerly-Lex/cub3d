/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:52:36 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:27:44 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*ptr;

	counter = 0;
	ptr = (unsigned char *)b;
	while (counter < len)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}

// writes a byte to a byte string

// int main()
// {
// 	char str1[50] = "London Bridge is falling down.";
// 	char str2[50] = "London Bridge is falling down.";

// 	memset(str1 + 17, '.', 8);
// 	ft_memset(str2 + 17, '.', 8);
// 	printf("After    memset():  %s \n", str1);
// 	printf("After ft_memset():  %s", str2);
// 	return (0);
// }
