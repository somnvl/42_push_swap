/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/24 22:04:03 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_dlst *s)
{
	int	i;
	int	pos;
	int	min;

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
