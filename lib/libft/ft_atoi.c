/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:38:41 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/11 09:54:29 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	counter;
	int	storage;
	int	operator;

	counter = 0;
	storage = 0;
	operator = 1;
	while ((str[counter] >= 9 && str[counter] <= 13) || str[counter] == 32)
		counter++;
	if (str[counter] == '-')
	{
		operator *= -1;
		counter++;
	}
	else if (str[counter] == '+')
		counter++;
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		storage *= 10;
		storage += str[counter] - '0';
		counter++;
	}
	return (storage * operator);
}

// converts ASCII string to integer

// int	main(void)
// {
// 	char str1[] = "12;3";

// 	printf("Original Atoi: %d\n", atoi(str1));
// 	printf("Own   ft_atoi: %d\n", ft_atoi(str1));
// 	return (0);
// }
