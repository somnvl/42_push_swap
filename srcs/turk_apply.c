/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/28 16:52:30 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Apply simultaneous rotations when both stacks must rotate
** in the same direction. While ca and cb share the same sign,
** we merge moves using rr (both up) or rrr (both down) and
** decrement/increment both costs together to reduce operations.
*/
static void	apply_both(t_dlst **a, t_dlst **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

/*
** Apply remaining rotations on stack A only.
** A positive cost means rotate up (ra), a negative cost means
** reverse rotate (rra). The cost is driven back to zero.
*/
void	apply_a(t_dlst **a, int *ca)
{
	while (*ca > 0)
	{
		ra(a);
		(*ca)--;
	}
	while (*ca < 0)
	{
		rra(a);
		(*ca)++;
	}
}

/*
** Apply remaining rotations on stack B only.
** A positive cost means rotate up (rb), a negative cost means
** reverse rotate (rrb). The cost is driven back to zero.
*/
static void	apply_b(t_dlst **b, int *cb)
{
	while (*cb > 0)
	{
		rb(b);
		(*cb)--;
	}
	while (*cb < 0)
	{
		rrb(b);
		(*cb)++;
	}
}

/*
** Execute the cheapest rotation plan for one reinsertion:
** 1) merge common-direction rotations using rr/rrr,
** 2) finish leftover rotations on A,
** 3) finish leftover rotations on B.
** After this, the caller typically performs pa to insert from B into A.
*/
void	apply_cheapest(t_dlst **a, t_dlst **b, int ca, int cb)
{
	apply_both(a, b, &ca, &cb);
	apply_a(a, &ca);
	apply_b(b, &cb);
}
