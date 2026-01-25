/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:26:35 by so                #+#    #+#             */
/*   Updated: 2026/01/25 22:25:04 by so               ###   ########.fr       */
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
	int op;	

	op = 0;
	step = chunk_step(size);
	max = size - 1;
	chunk_init(&start, &end, step, max);
	while (size > 3)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b);
			size--;
			op++;
		}
		 else if (!chunk_left(*a, start, end))
            chunk_next(&start, &end, step, max);
        else
            ra(a);
	}
	FT_DEBUG(("PHASE A: %d |\n", op));
}

/*
** Reinsert all elements from B to A using cheapest moves.
*/
void   phase_b(t_dlst **a, t_dlst **b)
{
    int ca;
    int cb;
    int op;

   	op = 0;
    while (*b)
    {
        pick_cheapest(*a, *b, &ca, &cb);
        apply_cheapest(a, b, ca, cb);
        pa(a, b);
        op += (ca > 0 ? ca : -ca) + (cb > 0 ? cb : -cb) + 1;
    }
	FT_DEBUG(("PHASE B: %d |\n", op));
}
