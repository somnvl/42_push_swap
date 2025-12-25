/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/25 18:38:08 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_dlst *s)
{
	int		tmp;
	t_dlst	*next;

	if (!s || !s->next)
		return ;
	next = s->next;
	tmp = s->content;
	s->content = next->content;
	next->content = tmp;
}

/* (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none. */
void	sa(t_dlst *a)
{
	if (!a || !a->next)
		return ;
	swap(a);
	ft_printf("sa\n");
}

/* (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none. */
void	sb(t_dlst *b)
{
	if (!b || !b->next)
		return ;
	swap(b);
	ft_printf("sb\n");
}

/* sa and sb at the same time. */
void	ss(t_dlst *a, t_dlst *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
