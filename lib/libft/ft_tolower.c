/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:49:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/07 14:52:39 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

// #include <ctype.h>
// int	main()
// {
// 	int	a = ' ';
// 	printf("Result of    tolower: %i\n", tolower(a));
// 	printf("Result of ft_tolower: %i", ft_tolower(a));
// 	return (0);
// }
