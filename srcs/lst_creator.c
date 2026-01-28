/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 17:05:33 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Detect if an argv entry contains spaces (quoted input like "1 2 3").
** If it contains at least one space, we will split it into multiple tokens.
*/
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

/*
** Free a NULL-terminated array returned by ft_split.
** Frees each token, then frees the array pointer itself.
*/
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

/*
** Convert a numeric string to a long.
** Handles optional leading '+' or '-' and assumes the string is digit-only
** afterwards (validation is expected to happen elsewhere in parsing).
*/
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

/*
** Convert one token to an int and append it to the list.
** The token is converted as long, checked against INT range,
** then stored as int in a new node added at the back.
** Returns 1 on success, 0 on overflow/underflow.
*/
static int	lst_nbr(t_dlst **lst, char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	db_lstadd_back(lst, db_lstnew((int)nbr));
	return (1);
}

/*
** Build the initial stack (list) from program arguments.
** Each argv element is either:
** - a single number token, or
** - a quoted string containing multiple numbers separated by spaces.
** For quoted strings, we split, validate, append each number, then free split.
** On any error (allocation failure or out-of-range value), we free everything
** built so far and return NULL.
*/
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
