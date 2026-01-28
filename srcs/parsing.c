/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 17:34:39 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Validate that argv strings contain only:
** - digits and spaces, 
** - optional '+'/'-' signs placed correctly.
** Rejects empty strings, missplaced signs, and invalid characters.
*/
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

/*
** Check the list for duplicate values.
** Uses a double traversal to compare each node with the rest of the list.
** Returns 1 if any duplicate content is found, 0 otherwise.
*/
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

/*
** Parse and validate program arguments into stack A.
** 1) Validate characters and sign placement in argv.
** 2) Build the list (supports quoted arguments split by spaces).
** 3) Reject duplicate values.
** Returns the created list on success, or NULL on any validation error.
*/
t_dlst	*parsing(int argc, char **argv)
{
	t_dlst	*stack_a;

	if (!valid_char(argc, argv))
		return (NULL);
	stack_a = lst_creator(argc, argv);
	if (!stack_a)
		return (NULL);
	if (check_duplicates(stack_a))
		return (free_list(stack_a), NULL);
	return (stack_a);
}
