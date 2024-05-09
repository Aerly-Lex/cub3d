/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:34:56 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/06 09:35:18 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 1)
	{
		index = (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
	return (index);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_fibonacci(42));
// 	return (0);
// }
