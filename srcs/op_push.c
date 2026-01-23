/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:44:19 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Swap the first two nodes of a stack by relinking pointers.
The head becomes the second node, the second becomes the new head,
and the rest of the list remains unchanged.
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
(push a) Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void	pa(t_dlst **a, t_dlst **b)
{
	push(b, a);
	ft_printf("pa\n");
}

/*
(push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void	pb(t_dlst **a, t_dlst **b)
{
	push(a, b);
	ft_printf("pb\n");
}
