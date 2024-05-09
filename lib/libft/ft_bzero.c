/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:11 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:01:49 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			counter;
	unsigned char	*ptr;

	counter = 0;
	ptr = (unsigned char *)s;
	while (counter < n)
	{
		ptr[counter] = 0;
		counter++;
	}
}

// int main()
// {
//     char str1[50] = "GeeksForGeeks is for programming geeks.";
// 	char str2[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str1);

//     // Fill 8 characters starting from str[13] with '.'
//     bzero(str1 + 13, 8);
// 	ft_bzero(str2 + 13, 8);

//     printf("After bzero():  %s \n", str1);
// 	printf("After ft_bzero():  %s", str2);
//     return 0;
// }
