/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 18:16:48 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Swap the first two nodes of a stack by relinking pointers.
** The second node becomes the new head, the first moves to second place,
** and the rest of the list remains unchanged.
*/
static void	swap(t_dlst **s)
{
	t_dlst	*first;
	t_dlst	*second;
	t_dlst	*third;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*s = second;
}

/*
** (swap a): Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one element or none.
*/
void	sa(t_dlst **a)
{
	swap(a);
	write(2, "sa\n", 3);
}

/*
** (swap b): Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one element or none.
*/
void	sb(t_dlst **b)
{
	swap(b);
	write(2, "sb\n", 3);
}

/*
** sa and sb at the same time.
*/
void	ss(t_dlst **a, t_dlst **b)
{
	swap(a);
	swap(b);
	write(2, "ss\n", 3);
}
