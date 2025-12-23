/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 19:08:18 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// /* (push a) Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty. */
void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (print)
		ft_printf("pa\n");
}

// /* (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty. */
void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (print)
		ft_printf("pb\n");
}

// /* (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one. */
void	ra(t_list *stack_a, int print)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
		stack_a = stack_a->next;
	stack_a = tmp;
	if (print)
		ft_printf("ra\n");
}

// /* (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one. */
void	rb(t_list *stack_b, int print)
{
	t_list	*tmp;

	tmp = stack_b;
	while (tmp)
		stack_b = stack_b->next;
	stack_b = tmp;
	if (print)
		ft_printf("rb\n");
}

// /* ra and rb at the same time. */
void	rr(t_list *stack_a, t_list *stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_printf("rr\n");
}

// /* (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one. */
void	rra(t_list *stack_a, int print)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
		stack_a = stack_a->next;
	stack_a = tmp;
	if (print)
		ft_printf("ra\n");
}

// /* (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. */
void	rrb(t_list *stack_b, int print)
{
	t_list	*tmp;

	tmp = stack_b;
	while (tmp)
		stack_b = stack_b->next;
	stack_b = tmp;
	if (print)
		ft_printf("rb\n");
}

// /* rra and rrb at the same time. */
void	rrr(t_list *stack_a, t_list *stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_printf("rrr\n");
}
