/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:14:59 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/17 21:44:39 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_supported(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

static void	ft_conversion(char c, va_list args, int *len)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		*len += 1;
	}
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		*len += 1;
	}
	if (c == 's')
		ft_putstr_pf(va_arg(args, char *), len);
	if (c == 'd' || c == 'i')
		ft_putnbr_pf(va_arg(args, int), len);
	if (c == 'u')
		ft_putnbr_u_pf(va_arg(args, int), len);
	if (c == 'x')
		ft_putnbr_base_pf(va_arg(args, int), "0123456789abcdef", c, len);
	if (c == 'X')
		ft_putnbr_base_pf(va_arg(args, int), "0123456789ABCDEF", c, len);
	if (c == 'p')
		ft_putnbr_base_p_pf((unsigned long long)
			va_arg(args, void *), "0123456789abcdef", c, len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_is_supported(str[i +1]) == 1 && str[i + 1])
		{
			i++;
			ft_conversion(str[i], args, &len);
		}
		else if (str[i] == '%' && ft_is_supported(str[i +1]) == 0 && str[i + 1])
			i++;
		else
		{
			ft_putchar_fd(str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(args);
	return (len);
}
