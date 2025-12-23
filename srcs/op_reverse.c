/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 20:17:49 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// /* (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one. */
void	rra(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
		a = a->next;
	a = tmp;
	ft_printf("rra\n");
}

// /* (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. */
void	rrb(t_list *b)
{
	t_list	*tmp;

	tmp = b;
	while (tmp)
		b = b->next;
	b = tmp;
	ft_printf("rrb\n");
}

// /* rra and rrb at the same time. */
void	rrr(t_list *a, t_list *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
