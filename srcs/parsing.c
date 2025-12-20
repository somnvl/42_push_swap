/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 01:18:01 by somenvie         ###   ########.fr       */
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
static int	check_quoted(int argc, char **argv)
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

/* Create the whole list containging each numbers 
	with  a split if needed. */
t_list	*lst_creator(int argc, char **argv)
{
	int		i;
	char	**split;
	t_list	*lst;
	
	lst = NULL;
	if (argc == 2)
	{
		i = 0;
		split = ps_split(argv[1], ' ');
		while (split[i])
		{
			ft_lstadd_back(&lst, ft_lstnew(split[i]));
			i++;
		}
		return (lst);
	}
	else if (argc > 2 && check_quoted(argc, argv))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&lst, ft_lstnew(argv[i]));
		if (argv[i][0] == '\0')
			return (NULL);
		i++;
	}
	return (lst);
}
