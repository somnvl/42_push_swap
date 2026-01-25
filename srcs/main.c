/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+              */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/25 19:11:20 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Free a doubly-linked list of t_dlst nodes.
** Iterates through the list, releasing each node to avoid memory leaks.
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
** Check if a stack is already sorted in ascending order.
** Returns 1 if empty, one element, or fully sorted; 0 otherwise.
*/
static int	already_sorted(t_dlst *a)
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
** Apply the Turkish sorting strategy for larger inputs.
** Splits work into phase A (push by chunks), sorts the remaining three in A,
** then reinserts from B and finally rotates A to its final sorted position.
*/
static void	turk_sort(int size, t_dlst **a, t_dlst **b)
{
	phase_a(size, a, b);
	sort_three(a);
	phase_b(a, b);
	final_rotate(a);
}

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
