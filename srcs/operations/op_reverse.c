/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/23 21:17:15 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Reverse rotate a stack by moving the last node to the front.
*/
static void	reverse_rotate(t_dlst **s)
{
	t_dlst	*last;
	t_dlst	*before_last;

	if (!s || !*s || !(*s)->next)
		return ;
	last = db_lstlast(*s);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *s;
	(*s)->prev = last;
	*s = last;
}

// /* (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one. */
void	rra(t_dlst **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// /* (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. */
void	rrb(t_dlst **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// /* rra and rrb at the same time. */
void	rrr(t_dlst **a, t_dlst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
