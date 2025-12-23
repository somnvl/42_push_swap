/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 20:16:37 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// /* (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one. */
void	ra(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
		a = a->next;
	a = tmp;
	ft_printf("ra\n");
}

// /* (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one. */
void	rb(t_list *b)
{
	t_list	*tmp;

	tmp = b;
	while (tmp)
		b = b->next;
	b = tmp;
	ft_printf("rb\n");
}

// /* ra and rb at the same time. */
void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
