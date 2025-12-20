/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 16:24:46 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check that all arguments input are digits only, 
	spaces or optional '+' or '-'. */
int	valid_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (j > 0 && ft_isdigit(argv[i][j - 1]))
					return (0);
				if (!ft_isdigit(argv[i][j + 1]))
					return (0);
			}
			else if (!ft_isdigit(argv[i][j]) && (argv[i][j]) != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Atoi with a long every arg in the lst. */
// static int	ft_atol(const char *nb)
// {
// 	int		i;
// 	int		sign;
// 	long	res;
// 	long	final;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	if (nb[i] == '-')
// 		sign = -1;
// 	if (nb[i] == '+' || nb[i] == '-')
// 		i++;
// 	while (nb[i])
// 	{
// 		res = (nb[i] - '0') + res * 10;
// 		i++;
// 	}
// 	final = res * sign;
// 	return (final);
// }

/* Main parsing function that check the validity of the args
	and put them in a list. */
t_list	*parsing(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (NULL);
	if (!valid_char(argc, argv))
		return (NULL);
	stack_a = lst_creator(argc, argv);
	if (!stack_a)
		return (NULL);
	// atol_args(stack_a);
	return (stack_a);
}
	// if (check_duplicates(stack_a))
	//     return (NULL);