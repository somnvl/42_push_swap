/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:22:10 by so                #+#    #+#             */
/*   Updated: 2026/01/28 18:54:35 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Phase A: reduce stack A to 3 elements by pushing to B.
** At each step, we pick the element in A that is cheapest to bring on top
** (best_pos_global + cost_to_top_len), rotate A accordingly, then pb.
** After each push, we optionally rb to keep smaller indexes deeper in B,
** which tends to make reinsertion (phase B) cheaper.
*/
static void	phase_a(int size, t_dlst **a, t_dlst **b)
{
	int	ca;
	int	pos;

	while (size > 3)
	{
		pos = best_pos_global(*a, size);
		ca = cost_to_top_len(size, pos);
		apply_a(a, &ca);
		pb(a, b, 1);
		size--;
		if (*b && (*b)->index < (size / 2))
			rb(b, 1);
	}
}

/*
** Phase B: reinsert all elements from B back into A using cheapest moves.
** We refresh positions in B, evaluate for each node in B the total cost to
** rotate A to its target insertion position and rotate B to the node.
** We apply merged rotations when possible (rr/rrr), finish remaining single
** rotations, then pa the chosen element into A.
*/
static void	phase_b(t_dlst **a, t_dlst **b)
{
	int	ca;
	int	cb;

	while (*b)
	{
		update_pos(*b);
		pick_cheapest(*a, *b, &ca, &cb);
		apply_cheapest(a, b, ca, cb);
		pa(a, b, 1);
	}
}

/*
** Final rotate: once all values are back in A, align the stack.
** We locate the position of the minimum index, convert it into a signed
** rotation cost (ra if positive, rra if negative), then execute exactly
** that cost so the smallest element ends up on top.
*/
static void	final_rotate(t_dlst **a)
{
	int	len;
	int	pos;
	int	cost;

	len = db_lstsize(*a);
	pos = find_min(*a);
	cost = cost_to_top_len(len, pos);
	while (cost > 0)
	{
		ra(a, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, 1);
		cost++;
	}
}

/*
** 1) Phase A pushes most elements to B while keeping moves low.
** 2) Sort the remaining 3 elements in A (base case).
** 3) Phase B reinserts everything from B into A with cheapest combined costs.
** 4) Final rotate to place the smallest value at the top (fully sorted A).
*/
void	turk_sort(int size, t_dlst **a, t_dlst **b)
{
	phase_a(size, a, b);
	sort_three(a);
	phase_b(a, b);
	final_rotate(a);
}
