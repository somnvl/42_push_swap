/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:08:48 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/06 23:08:50 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	dest;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		dest = (n % 10) + '0';
		n /= 10;
		ft_putnbr_fd(n, fd);
		write(fd, &dest, 1);
	}
	else
	{
		dest = n + '0';
		write(fd, &dest, 1);
	}
}
