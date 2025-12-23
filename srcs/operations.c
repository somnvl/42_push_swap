/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 18:18:26 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none. */
void	sa(t_list *stack_a, int print)
{
	int		*swap;
	t_list	*tmp;

	if (!stack_a->next || !stack_a->content)
		return ;
	tmp = stack_a->next;
	swap = stack_a->content;
	stack_a->content = tmp->content;
	tmp->content = swap;
	if (print == 1)
		ft_printf("sa\n");
}

/* (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none. */
void	sb(t_list *stack_b, int print)
{
	int		*swap;
	t_list	*tmp;

	if (!stack_b->next || !stack_b->content)
		return ;
	tmp = stack_b->next;
	swap = stack_b->content;
	stack_b->content = tmp->content;
	tmp->content = swap;
	if (print == 1)
		ft_printf("sb\n");
}

// /* sa and sb at the same time. */
void	ss(t_list *stack_a, t_list *stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}

// /* (push a) Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty. */
void	pa(t_list *stack_b, t_list **stack_a, int print)
{
	if (!stack_b->content)
		return ;
	ft_lstadd_front(stack_a, ft_lstnew(stack_b->content));
	rb(stack_b, 0);
	free(ft_lstlast(stack_b));
	if (print == 1)
		ft_printf("pa\n");
}

// /* (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty. */
void	pb(t_list *stack_a, t_list **stack_b, int print)
{
	if (!stack_a->content)
		return ;
	ft_lstadd_front(stack_b, ft_lstnew(stack_a->content));
	ra(stack_a, 0);
	free(ft_lstlast(stack_a));
	if (print == 1)
		ft_printf("pa\n");
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
	if (print == 1)
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
	if (print == 1)
		ft_printf("rb\n");
}

// /* ra and rb at the same time. */
void	rr(t_list *stack_a, t_list *stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print == 1)
		ft_printf("rr\n");
}

// /* (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the last one. */
void	rra(t_list *stack_a, int print)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
		stack_a = stack_a->next;
	stack_a = tmp;
	if (print == 1)
		ft_printf("ra\n");
}

// /* (reverse rotate b): Shift down all elements of stack b by 1.
// The first element becomes the last one. */
void	rrb(t_list *stack_b, int print)
{
	t_list	*tmp;

	tmp = stack_b;
	while (tmp)
		stack_b = stack_b->next;
	stack_b = tmp;
	if (print == 1)
		ft_printf("rb\n");
}

// /* rra and rrb at the same time. */
void	rrr(t_list *stack_a, t_list *stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}
