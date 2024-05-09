/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:16:45 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 13:22:18 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	counter;
	size_t	total_s;

	counter = 0;
	total_s = ft_strlen(s);
	if (total_s < start)
		return (ft_strdup(""));
	if (total_s <= start + len)
		len = total_s - start;
	new_s = malloc(sizeof(char) * len + 1);
	if (new_s == NULL)
		return (NULL);
	while (counter < len)
	{
		new_s[counter] = s[start + counter];
		counter++;
	}
	new_s[counter] = '\0';
	return (new_s);
}

// cuts a part of a string s and returns a new string with the cutted part

// int	main(void)
// {
// 	char const s1[] = "aloh";

// 	printf("%s", ft_substr(s1, 2, 3));
// 	return (0);
// }
