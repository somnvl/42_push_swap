/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:26:35 by so                #+#    #+#             */
/*   Updated: 2026/01/25 21:49:18 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Push stack A elements to B by chunks until 3 elements remain.
*/
void	phase_a(int size, t_dlst **a, t_dlst **b)
{
	int	step;
	int	start;
	int	end;
	int	max;

	step = chunk_step(size);
	max = size - 1;
	chunk_init(&start, &end, step, max);
	while (size > 3)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b);
			size--;
		}
		 else if (!chunk_left(*a, start, end))
            chunk_next(&start, &end, step, max);
        else
            ra(a);
	}
}

/*
** Reinsert all elements from B to A using cheapest moves.
*/
void	phase_b(t_dlst **a, t_dlst **b)
{
	int	ca;
	int	cb;

	while (*b)
	{
		pick_cheapest(*a, *b, &ca, &cb);
		apply_cheapest(a, b, ca, cb);
		pa(a, b);
	}
}
