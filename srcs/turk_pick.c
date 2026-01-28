/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_pick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/28 17:28:23 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Compute minimum and maximum index currently present in stack A.
** Helps decide if a B element should be inserted before the current minimum.
*/
static void	minmax_idx(t_dlst *a, int *min_i, int *max_i)
{
	*min_i = a->index;
	*max_i = a->index;
	while (a)
	{
		if (a->index < *min_i)
			*min_i = a->index;
		if (a->index > *max_i)
			*max_i = a->index;
		a = a->next;
	}
}

/*
** Return the target position in A where b_idx should be inserted.
** If b_idx is outside A's [min..max], we insert before the current minimum.
** Otherwise, we insert before the smallest A index that is strictly > b_idx.
*/
static int	target_pos_a(t_dlst *a, int b_idx)
{
	int	min_i;
	int	max_i;
	int	best_pos;
	int	best_idx;
	int	pos;

	if (!a)
		return (0);
	minmax_idx(a, &min_i, &max_i);
	if (b_idx < min_i || b_idx > max_i)
		return (find_min(a));
	best_pos = 0;
	best_idx = INT_MAX;
	pos = 0;
	while (a)
	{
		if (a->index > b_idx && a->index < best_idx)
		{
			best_idx = a->index;
			best_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (best_pos);
}

/*
** Compute the combined rotation cost for A and B.
** If both costs share the same sign, rr/rrr can merge moves, so the total
** is the maximum absolute cost. Otherwise, totals add up (sum of abs).
*/
static int	total_cost(int ca, int cb)
{
	int	abs_a;
	int	abs_b;

	abs_a = abs_i(ca);
	abs_b = abs_i(cb);
	if (ca > 0 && cb > 0)
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	if (ca < 0 && cb < 0)
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

/*
** Select in stack B the element that requires the fewest rotations
** to be inserted into stack A, and return its rotation costs.
*/

void	pick_cheapest(t_dlst *a, t_dlst *b, int *ca, int *cb)
{
	int		len_a;
	int		len_b;
	int		best_total;
	int		t_ca;
	int		t_cb;

	len_a = db_lstsize(a);
	len_b = db_lstsize(b);
	best_total = INT_MAX;
	while (b)
	{
		t_ca = cost_to_top_len(len_a, target_pos_a(a, b->index));
		t_cb = cost_to_top_len(len_b, b->pos);
		if (total_cost(t_ca, t_cb) < best_total)
		{
			best_total = total_cost(t_ca, t_cb);
			*ca = t_ca;
			*cb = t_cb;
		}
		b = b->next;
	}
}
