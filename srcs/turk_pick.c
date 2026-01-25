/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_pick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:05:45 by so                #+#    #+#             */
/*   Updated: 2026/01/25 18:52:26 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find optimal insertion position in A for element with index i 
** (next larger element).
*/
static int	pos_a(t_dlst *a, int i)
{
	t_dlst	*tmp;
	int		index;
	int		pos;
	int		j;

	tmp = a;
	index = INT_MAX;
	pos = 0;
	j = 0;
	while (tmp)
	{
		if (tmp->index > i && tmp->index < index)
		{
			index = tmp->index;
			pos = j;
		}
		tmp = tmp->next;
		j++;
	}
	if (index != INT_MAX)
		return (pos);
	return (find_min(a));
}

/*
** Get position index of node in stack B (0 = top).
*/
static int	pos_b(t_dlst *b, t_dlst *node)
{
	int	i;

	i = 0;
	while (b && b != node)
	{
		i++;
		b = b->next;
	}
	return (i);
}

/*
** Calculate rotation cost to bring position to top (positive ra, negative rra).
*/
static int	cost_to_top(t_dlst *s, int pos)
{
	int	len;

	len = db_lstsize(s);
	if (len <= 1 || pos <= 0)
		return (0);
	if (pos <= len / 2)
		return (pos);
	return (pos - len);
}

/*
** Calculate total cost of rotations, optimizing parallel moves.
*/
static int	total_cost(int ca, int cb)
{
	if (ca > 0 && cb > 0)
	{
		if (ca > cb)
			return (ca);
		return (cb);
	}
	if (ca < 0 && cb < 0)
	{
		if (-ca > -cb)
			return (-ca);
		return (-cb);
	}
	if (ca < 0)
		return (-ca + cb);
	else if (cb < 0)
		return (ca + -cb);
	return (0);
}

/*
** Find element in B with minimum total rotation cost to insert into A.
*/
void	pick_cheapest(t_dlst *a, t_dlst *b, int *ca, int *cb)
{
	t_dlst	*tmp;
	int		tmp_ca;
	int		tmp_cb;
	int		tmp_total;
	int		total;

	tmp = b;
	total = INT_MAX;
	while (tmp)
	{
		tmp_ca = cost_to_top(a, pos_a(a, tmp->index));
		tmp_cb = cost_to_top(b, pos_b(b, tmp));
		tmp_total = total_cost(tmp_ca, tmp_cb);
		if (tmp_total < total)
		{
			*ca = tmp_ca;
			*cb = tmp_cb;
			total = tmp_total;
		}
		tmp = tmp->next;
	}
}
