/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 18:51:52 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* MAIN */
void	free_list(t_list *lst);

/* PARSING */
t_list	*parsing(int argc, char **argv);
t_list	*lst_creator(int argc, char **argv);

/* OPERATIONS */
void	sa(t_list *stack_a, int print);
void	sb(t_list *stack_b, int print);
void	ss(t_list *stack_a, t_list *stack_b, int print);
void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	ra(t_list *stack_a, int print);
void	rb(t_list *stack_b, int print);
void	rr(t_list *stack_a, t_list *stack_b, int print);
void	rra(t_list *stack_a, int print);
void	rrb(t_list *stack_b, int print);
void	rrr(t_list *stack_a, t_list *stack_b, int print);

#endif