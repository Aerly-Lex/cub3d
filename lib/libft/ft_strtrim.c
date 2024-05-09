/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:28 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 11:19:49 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_checker(char c, char const *set)
{
	size_t	counter;

	counter = 0;
	while (set[counter] != '\0')
	{
		if (set[counter] == c)
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	counter;
	char	*new_s;

	start = 0;
	end = ft_strlen(s1);
	counter = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[start] != '\0' && set_checker(s1[start], set))
		start++;
	while (end > start && set_checker(s1[end - 1], set))
		end--;
	new_s = malloc(sizeof(char) * (end - start + 1));
	if (new_s == NULL)
		return (NULL);
	while (start < end)
		new_s[counter++] = s1[start++];
	new_s[counter] = '\0';
	return (new_s);
}

// trim beginning an end of string with the given "*set" cahracters

// int	main(void)
// {
// 	char const s1[] = "  \t \t \n   \n\n\n\t";
// 	char const set[] = "";

// 	printf("%s", ft_strtrim(s1, set));
// 	return (0);
// }
