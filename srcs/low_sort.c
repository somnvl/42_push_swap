/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 16:31:10 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the position (0-based) of the smallest index in the stack.
** We scan once, tracking the current minimum index and its position,
** and return the position of that minimum to help choose rotations.
*/
int	find_min(t_dlst *s)
{
	int	i;
	int	pos;
	int	min;

	if (!s)
		return (0);
	i = 0;
	pos = 0;
	min = s->index;
	while (s)
	{
		if (s->index < min)
		{
			pos = i;
			min = s->index;
		}
		s = s->next;
		i++;
	}
	return (pos);
}

/*
** Sort exactly 3 nodes in stack A using the minimal set of operations.
** We compare the three indexes and apply the known optimal cases
** (sa/ra/rra or a 2-step combo) to reach ascending order.
*/
void	sort_three(t_dlst **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
}

/*
** Sort exactly 4 nodes using stack B as temporary storage.
** We bring the smallest index to the top of A with the cheapest rotation,
** push it to B, sort the remaining 3 in A, then pa to restore the minimum.
*/
void	sort_four(t_dlst **a, t_dlst **b)
{
	int	min_pos;
	int	size;

	min_pos = find_min(*a);
	size = 4;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

/*
** Sort exactly 5 nodes by reducing the problem to sort_four.
** We rotate A to bring the minimum index to the top, pb it to B,
** sort the remaining 4 elements in A, then pa to put the minimum back.
*/
void	sort_five(t_dlst **a, t_dlst **b)
{
	int	min_pos;
	int	size;

	min_pos = find_min(*a);
	size = 5;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

/*
** Small-sort dispatcher for inputs up to 5 nodes.
** Uses specialized routines (and B when needed) to keep move count low.
*/
void	low_sort(int size, t_dlst **a, t_dlst **b)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
