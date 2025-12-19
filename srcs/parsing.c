/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 00:20:31 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check that all arguments input are digits only, whitespaces 
	allowed, one '+' or '-' before a digit allowed too. */
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

/* Check if the recived arg is quoted, meaning it contains multiple 
	numbers to split */
static int	is_quoted(int argc, char **argv)
{
	int	i;
	
	i = 0;
	while (argv[argc][i])
	{
		if ((argv[argc][i]) == ' ')
			return (1);
		i++;
	}
	return (0);
}

/* Create the whole list containging each indivuals 
	numbers through a split of needed. */
t_list	*lst_creator(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_list	*lst;
	
	i = 1;
	lst = ft_lstnew(argv[i++]);
	while (i < argc)
	{
		if (is_quoted(i, argv))
		{
			j = 0;
			split = ps_split(argv[i], ' ');
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
