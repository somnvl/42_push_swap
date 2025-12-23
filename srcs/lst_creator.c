/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 16:08:29 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/* Split every args into a lst. */
t_lst	*lst_creator(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_lst	*lst;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		if (is_quoted(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split[j])
			{
				ft_lstadd_back_db(&lst, ft_lstnew_db(ft_strdup(split[j])));
				j++;
			}
			free_split(split);
		}
		else
			ft_lstadd_back_db(&lst, ft_lstnew_db(ft_strdup(argv[i])));
		i++;
	}
	return (lst);
}
