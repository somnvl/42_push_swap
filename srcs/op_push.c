/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 19:16:09 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Push the first node from src stack to the top of dst stack.
** The head of src is detached and becomes the new head of dst,
** while preserving correct prev/next links on both stacks.
*/
static void	push(t_dlst **src, t_dlst **dst)
{
	t_dlst	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->prev = NULL;
	*dst = tmp;
}

/*
** (push a) Take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/
void	pa(t_dlst **a, t_dlst **b, int print)
{
	push(b, a);
	if (print == 1)
		ft_printf("pa\n");
}

/*
** (push b): Take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/
void	pb(t_dlst **a, t_dlst **b, int print)
{
	push(a, b);
	if (print == 1)
		ft_printf("pb\n");
}
