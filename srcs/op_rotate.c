/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/25 20:50:13 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Rotate a stack by moving the first node to the end of the list.
*/
static void	rotate(t_dlst **s)
{
	t_dlst	*first;
	t_dlst	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	last = db_lstlast(*s);
	*s = first->next;
	(*s)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/* 
** (rotate a): Shift up all elements of stack a by 1.
** The first element becomes the last one. 
*/
void	ra(t_dlst **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/* 
** (rotate b): Shift up all elements of stack b by 1.
** The first element becomes the last one.
*/
void	rb(t_dlst **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/*
** ra and rb at the same time.
*/
void	rr(t_dlst **a, t_dlst **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
