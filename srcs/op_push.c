/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 20:35:47 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* (push a) Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pa\n");
}

/* (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pb\n");
}
