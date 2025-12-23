/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:06:50 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 15:55:05 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none. */
void	*sa(t_lst *stack_a)
{

}

/* (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none. */
void	*sb(t_lst *stack_b)
{

}

/* sa and sb at the same time. */
void	*ss(t_lst *stack_a, t_lst *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

/* (push a) Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	*pa(t_lst *stack_a, t_lst *stack_b)
{

}

/* (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	*pb(t_lst *stack_a, t_lst *stack_b)
{

}

/* (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */
void	*ra(t_lst *stack_a)
{

}

/* (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one. */
void	*rb(t_lst *stack_b)
{

}

/* ra and rb at the same time. */
void	*rr(t_lst *stack_a, t_lst *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

/* (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the last one. */
void	*rra(t_lst *stack_a)
{

}

/* (reverse rotate b): Shift down all elements of stack b by 1.
The first element becomes the last one. */
void	*rrb(t_lst *stack_b)
{

}

/* rra and rrb at the same time. */
void	*rrr(t_lst *stack_a, t_lst *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
