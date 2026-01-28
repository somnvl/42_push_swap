/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:47:14 by so                #+#    #+#             */
/*   Updated: 2026/01/28 20:09:00 by so               ###   ########.fr       */
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
** Compare two operation strings for an exact match.
** Returns 1 if both strings are identical and end at the same time,
** otherwise returns 0.
*/
int	check_op(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

/*
** Execute a single operation on stacks A and B.
** The operation string must exactly match a valid instruction.
** Returns 1 if the operation is valid and executed, 0 otherwise.
*/
int	exec_op(char *op, t_dlst **a, t_dlst **b)
{
	if (check_op(op, "sa\n"))
		return (sa(a, 0), 1);
	if (check_op(op, "sb\n"))
		return (sb(b, 0), 1);
	if (check_op(op, "ss\n"))
		return (ss(a, b, 0), 1);
	if (check_op(op, "pa\n"))
		return (pa(a, b, 0), 1);
	if (check_op(op, "pb\n"))
		return (pb(a, b, 0), 1);
	if (check_op(op, "ra\n"))
		return (ra(a, 0), 1);
	if (check_op(op, "rb\n"))
		return (rb(b, 0), 1);
	if (check_op(op, "rr\n"))
		return (rr(a, b, 0), 1);
	if (check_op(op, "rra\n"))
		return (rra(a, 0), 1);
	if (check_op(op, "rrb\n"))
		return (rrb(b, 0), 1);
	if (check_op(op, "rrr\n"))
		return (rrr(a, b, 0), 1);
	return (0);
}
