/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/25 18:48:05 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check that all arguments input are digits only, 
	spaces or optional '+' or '-'. */
static int	valid_char(int argc, char **argv)
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

// /* Looks for duplicates in the lst. */
static int	check_duplicates(t_dlst *lst)
{
	t_dlst	*tmp1;
	t_dlst	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

/* Main parsing function that check the validity of the args
	and put them in a list. */
t_dlst	*parsing(int argc, char **argv)
{
	t_dlst	*stack_a;

	if (argc < 2)
		return (NULL);
	if (!valid_char(argc, argv))
		return (NULL);
	stack_a = lst_creator(argc, argv);
	if (!stack_a)
		return (free_list(stack_a), NULL);
	if (check_duplicates(stack_a))
		return (free_list(stack_a), NULL);
	return (stack_a);
}
