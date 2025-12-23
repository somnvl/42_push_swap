/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 16:07:57 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_lst
{
	struct s_lst	*prev;
	void			*content;
	struct s_lst	*next;
}					t_lst;


/* PARSING */
t_lst	*parsing(int argc, char **argv);
t_lst	*lst_creator(int argc, char **argv);
t_lst	*ft_lstnew_db(void *content);
void	ft_lstadd_back_db(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast_db(t_lst *lst);

/* OPERATIONS */
void	*sa(t_lst *stack_a);
void	*sb(t_lst *stack_b);
void	*ss(t_lst *stack_a, t_lst *stack_b);
void	*pa(t_lst *stack_a, t_lst *stack_b);
void	*pb(t_lst *stack_a, t_lst *stack_b);
void	*ra(t_lst *stack_a);
void	*rb(t_lst *stack_b);
void	*rr(t_lst *stack_a, t_lst *stack_b);
void	*rra(t_lst *stack_a);
void	*rrb(t_lst *stack_b);
void	*rrr(t_lst *stack_a, t_lst *stack_b);

#endif