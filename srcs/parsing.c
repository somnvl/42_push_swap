/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/19 19:20:07 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	digits_only(int argc, char **argv)
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
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || digits_only(argc, argv) == 1)
		ft_printf("Error\n");
	else
		ft_printf("OK\n");
	
	// generate my lst with a split
	// atoi each content and filter INT MIN and MAX
	// check for duplicata
}

