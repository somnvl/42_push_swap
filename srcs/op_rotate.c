/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:01:57 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_stack(t_list *s)
{
	t_list	*tmp;
	int		*first_content;
	
	if (!s || !s->next)
		return ;
	tmp = s;
	first_content = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first_content;
}

// /* (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one. */
void	ra(t_list *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

// /* (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one. */
void	rb(t_list *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

// /* ra and rb at the same time. */
void	rr(t_list *a, t_list *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
