/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:05:36 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/16 10:30:32 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	negative(int *n, int fd)
{
	ft_putchar('-', fd);
	*n *= -1;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		arr[12];
	int		counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
		negative(&n, fd);
	else if (n == 0)
		ft_putchar('0', fd);
	while (n > 0)
	{
		arr[counter] = (n % 10) + '0';
		n /= 10;
		counter++;
	}
	while (counter--)
		ft_putchar(arr[counter], fd);
}

// int	main(void)
// {
// 	int n = -504510;
// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }
