/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/25 18:49:12 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Apply parallel rotations when both stacks rotate same direction (rr/rrr).
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
** Apply all A stack rotations (ra for positive, rra for negative).
*/
static void	apply_a(t_dlst **a, int *ca)
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
** Apply all B stack rotations (rb for positive, rrb for negative).
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
** Apply cheapest move sequence: parallel rotations first, then individual.
*/
void	apply_cheapest(t_dlst **a, t_dlst **b, int ca, int cb)
{
	apply_both(a, b, &ca, &cb);
	apply_a(a, &ca);
	apply_b(b, &cb);
}
