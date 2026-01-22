/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:18:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/19 22:15:38 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_pf(unsigned int arg, char *base, char c, int *len)
{
	unsigned long long	nb;
	unsigned int		base_len;

	if (arg == 0 && c == 'p')
		return (ft_putstr_pf("(nil)", len));
	if (c == 'p')
		ft_putstr_pf("0x", len);
	base_len = ft_strlen(base);
	if (arg < 0)
		nb = 2147483647 - (arg * -1);
	else
		nb = arg;
	if (nb >= base_len)
		ft_putnbr_base_pf(nb / base_len, base, '\0', len);
	ft_putchar_fd(base[nb % base_len], 1);
	*len += 1;
}

void	ft_putnbr_base_p_pf(unsigned long long arg, char *base, char c, int *l)
{
	unsigned long long	nb;
	unsigned int		base_len;

	if (arg == 0 && c == 'p')
		return (ft_putstr_pf("(nil)", l));
	if (c == 'p')
		ft_putstr_pf("0x", l);
	base_len = ft_strlen(base);
	if (arg < 0)
		nb = 2147483647 - (arg * -1);
	else
		nb = arg;
	if (nb >= base_len)
		ft_putnbr_base_p_pf(nb / base_len, base, '\0', l);
	ft_putchar_fd(base[nb % base_len], 1);
	*l += 1;
}

void	ft_putstr_pf(char *s, int *len)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		*len += ft_strlen(s);
	}
}

void	ft_putnbr_pf(int n, int *len)
{
	int	dest;

	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648", len));
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', 1);
		*len += 1;
	}
	if (n > 9)
	{
		dest = (n % 10) + '0';
		n /= 10;
		ft_putnbr_pf(n, len);
		ft_putchar_fd(dest, 1);
		*len += 1;
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*len += 1;
	}
}

void	ft_putnbr_u_pf(unsigned int n, int *len)
{
	unsigned int	dest;

	if (n > 9)
	{
		dest = (n % 10) + '0';
		n /= 10;
		ft_putnbr_u_pf(n, len);
		ft_putchar_fd(dest, 1);
		*len += 1;
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*len += 1;
	}
}
