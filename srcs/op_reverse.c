/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:54:11 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_dlst *s)
{
	t_dlst	*tmp;
	int		*last;

	if (!s || !s->next)
		return ;
	tmp = db_lstlast(s);
	last = tmp->content;
	while (tmp->prev)
	{
		tmp->content = tmp->prev->content;
		tmp = tmp->prev;
	}
	tmp->content = last;
}

// /* (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one. */
void	rra(t_dlst *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// /* (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. */
void	rrb(t_dlst *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// /* rra and rrb at the same time. */
void	rrr(t_dlst *a, t_dlst *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
