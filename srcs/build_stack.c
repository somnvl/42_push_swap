/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 15:55:04 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Atoi every arg in the lst. */
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

/* Check if the recived arg is quoted, meaning it contains multiple 
	numbers to split */
static int	is_quoted(char *argv)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		if ((argv[i]) == ' ')
			return (1);
		i++;
	}
	return (0);
}

/* Split every args into a lst. */
t_list	*lst_creator(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_list	*lst;
	
	i = 1;
	lst = NULL;
	while (i < argc)
	{	
		if (argv[i][0] == '\0')
			return (NULL);
		if (is_quoted(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split[j])
			{
				ft_lstadd_back(&lst, ft_lstnew(split[j]));
				j++;
			}
		}
		else
			ft_lstadd_back(&lst, ft_lstnew(argv[i]));
		i++;
	}
	return (lst);
}
