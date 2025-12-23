/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:25:12 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_dlst *s)
{
	t_dlst	*tmp;
	int		*first;

	if (!s || !s->next)
		return ;
	tmp = s;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
}

// /* (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one. */
void	ra(t_dlst *a)
{
	rotate(a);
	ft_printf("ra\n");
}

// /* (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one. */
void	rb(t_dlst *b)
{
	rotate(b);
	ft_printf("rb\n");
}

// /* ra and rb at the same time. */
void	rr(t_dlst *a, t_dlst *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
