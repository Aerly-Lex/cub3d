/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:02:07 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:17:32 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (*c != '\0')
	{
		len++;
		c += 1;
	}
	return (len);
}

// int main(void)
// {
// 	char test_chars1[] = {"This is limitless"};
// 	char test_chars2[] = {""};
// 	char test_chars3[] = {"Stay a while and listen to the story of a..."};
// 	char test_chars4[] = {"#$%B hH$^@@Ag 846/*45^&@$%%V 2h2J@2545"};

// 	printf("'%zu' is 17 .\n", ft_strlen(test_chars1));
// 	printf("'%zu' is 0 .\n", ft_strlen(test_chars2));
// 	printf("'%zu' is 44 .\n", ft_strlen(test_chars3));
// 	printf("'%zu' is 38 .\n", ft_strlen(test_chars4));
// 	return 0;
// }
