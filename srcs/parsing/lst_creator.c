/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/25 19:08:37 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

/* Free the char ** containing double quoted args. */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Atol with a long every arg in the lst. */
static long	ft_atol(const char *nb)
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
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i])
	{
		res = (nb[i] - '0') + res * 10;
		i++;
	}
	final = res * sign;
	return (final);
}

/* Atol the arg and put it in the lst. */
static int	lst_nbr(t_dlst **lst, char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	db_lstadd_front(lst, db_lstnew((int)nbr));
	return (1);
}

/* Split every args into a lst. */
t_dlst	*lst_creator(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_dlst	*lst;

	lst = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_quoted(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (NULL);
			j = 0;
			while (split[j])
				if (!lst_nbr(&lst, split[j++]))
					return (free_split(split), free_list(lst), NULL);
			free_split(split);
		}
		else if (!lst_nbr(&lst, argv[i]))
			return (free_list(lst), NULL);
		i++;
	}
	return (lst);
}
