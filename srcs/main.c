/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:25:17 by so                #+#    #+#             */
/*   Updated: 2026/01/28 18:12:08 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Free a doubly-linked list of t_dlst nodes.
** Walks forward using a temporary pointer, frees each node, and leaves
** no allocations behind. Safe to call with NULL.
*/
void	free_list(t_dlst *lst)
{
	t_dlst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

/*
** Check if stack A is already sorted in ascending order by value.
** Empty or single-node stacks are considered sorted (returns 1).
** Returns 0 as soon as a descending pair is found.
*/
int	already_sorted(t_dlst *a)
{
	t_dlst	*current;

	if (!a || !a->next)
		return (1);
	current = a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
** Program entry point:
** 1) Parse and validate arguments into stack A (stack B starts empty).
** 2) Early exits: no args, parse error, or already sorted input.
** 3) Normalize values into indexes for algorithmic comparisons.
** 4) Dispatch: small inputs use low_sort, larger inputs use turk_sort.
** 5) Free both stacks before exiting.
*/
int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	int		size;

	a = parsing(argc, argv);
	b = NULL;
	if (argc < 2)
		return (free_list(a), 0);
	if (!a)
		return (free_list(a), ft_printf("Error\n"), 1);
	if (already_sorted(a))
		return (free_list(a), 0);
	normalize(a);
	size = db_lstsize(a);
	if (size <= 5)
		low_sort(size, &a, &b);
	else
		turk_sort(size, &a, &b);
	return (free_list(a), free_list(b), 0);
}
