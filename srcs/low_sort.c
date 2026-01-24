/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/24 16:39:32 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_dlst *s)
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

static void sort_three(t_dlst **a)
{
    int first = (*a)->index;
    int second = (*a)->next->index;
    int third = (*a)->next->next->index;
    
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
        sa(a);
    else if (first < second && second > third && first > third)
        rra(a);
    else if (first > second && second > third)
	{
        sa(a);
        rra(a);
	}
}

static void sort_four(t_dlst **a, t_dlst **b)
{
    int	pos;
	
	pos = find_min(*a);
    if (pos == 1)
		sa(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);		
	}
	else if (pos == 3)
		rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

// static void	sort_five(t_dlst **a, t_dlst **b)
// {
	
// }

void	low_sort(int size, t_dlst **a, t_dlst **b)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	// else if (size == 5)
	// 	sort_five(a, b);
}
