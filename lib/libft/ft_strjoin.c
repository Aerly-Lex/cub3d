/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:14:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:17:21 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;
	size_t	counter;

	counter = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_s == NULL)
		return (NULL);
	while (counter < s1_len)
	{
		new_s[counter] = s1[counter];
		counter++;
	}
	counter = 0;
	while (counter < s2_len)
	{
		new_s[s1_len + counter] = s2[counter];
		counter++;
	}
	new_s[s1_len + s2_len] = '\0';
	return (new_s);
}

// Concatenates two strings into a new string (with malloc)

// int	main(void)
// {
// 	char s1[] = "London Bridge is falling down";
// 	char s2[] = "\nMy Fair Lady";

// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }
