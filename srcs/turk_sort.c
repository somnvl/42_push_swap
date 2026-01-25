/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:26:35 by so                #+#    #+#             */
/*   Updated: 2026/01/25 15:49:14 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		else
			ra(a);
		if (!chunk_left(*a, start, end))
			chunk_next(&start, &end, step, max);
	}
}

void	phase_b(t_dlst **a, t_dlst **b)
{
	int	cost_a;
	int	cost_b;

	while (*b)
	{
		pick_cheapest(*a, *b, &cost_a, &cost_b);
		apply_cheapest(a, b, cost_a, cost_b);
		pa(a, b);
	}
}
