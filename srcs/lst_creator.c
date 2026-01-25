/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/25 18:42:16 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Check if argv string contains spaces (indicating quoted input).
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
** Free memory from split string array.
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
** Convert string to long integer with sign handling.
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
** Parse string to int and add to list, validate INT range.
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
** Create stack list from argv, handling quoted multi-number strings.
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
