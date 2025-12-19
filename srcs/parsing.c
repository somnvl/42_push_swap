/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/19 22:13:19 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Function to check that all arguments input are digits only,
	whitespaces allowed, one '+' or '-' before a digit allowed too. */
int	parsing_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (j > 0 && ft_isdigit(argv[i][j - 1]))
					return (1);
				if (!ft_isdigit(argv[i][j + 1]))
					return (1);
			}
			else if (!ft_isdigit(argv[i][j]) && !ft_iswhitespace(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
