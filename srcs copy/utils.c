/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 01:48:48 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check if the recived arg is quoted, meaning it contains multiple 
	numbers to split */
int	check_quoted(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j]) == ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atol(const char *nb)
{
	int		i;
	int		sign;
	long	res;
	long	final;

	i = 0;
	res = 0;
	sign = 1;
	if (nb[i] == '-')
		sign = -1;
	if (nb[i] == '-' || nb[i] == '-')
		i++;
	while (nb[i])
	{
		res = (nb[i] - '0') + res * 10;
		i++;
	}
	final = res * sign;
	if (final < INT_MIN || final > INT_MAX)
		return (0);
	return (final);
}
