/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:35:05 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/06 09:35:06 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= nb && i <= 46340)
	{
		if (nb == i * i)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_sqrt(256));
// 	return (0);
// }
