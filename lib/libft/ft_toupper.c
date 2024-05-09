/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:29:58 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/10 11:53:14 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// #include <ctype.h>
// int	main()
// {
// 	int	a = 97;
// 	printf("Result of    toupper: %i\n", toupper(a));
// 	printf("Result of ft_toupper: %i", ft_toupper(a));
// 	return (0);
// }
