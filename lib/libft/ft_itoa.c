/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:15:43 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/13 11:20:01 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*creator(long nbr, int size)
{
	char	*str;

	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nbr != 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (size == 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		size;

	nbr = n;
	size = 0;
	if (n < 0)
	{
		size++;
		nbr *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	if (nbr == 0)
		return (creator(nbr, 1));
	else
		return (creator(nbr, size));
}

// int	main(void)
// {
// 	int	n = -156000;

// 	printf("%s", ft_itoa(n));
// 	return (0);
// }
