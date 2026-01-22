/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:30:26 by somenvie          #+#    #+#             */
/*   Updated: 2025/09/21 16:30:29 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_dest_size(int nb)
{
	int	digits_count;

	digits_count = 0;
	if (nb == 0)
		return (2);
	if (nb < 0)
	{
		nb *= -1;
		digits_count++;
	}
	while (nb != 0)
	{
		nb /= 10;
		digits_count++;
	}
	return (digits_count + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*dest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_get_dest_size(n);
	dest = malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	i = size - 1;
	dest[i--] = '\0';
	if (n == 0)
		dest[i] = '0';
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
	}
	while (n > 0)
	{
		dest[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
