/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:34:27 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_dlst
{
	struct s_dlst	*prev;
	void			*content;
	struct s_dlst	*next;
}					t_dlst;

/* LST */
void	free_list(t_dlst *lst);
void	db_lstadd_front(t_dlst **lst, t_dlst *new);
t_dlst	*db_lstnew(void *content);

/* PARSING */
t_dlst	*parsing(int argc, char **argv);
t_dlst	*lst_creator(int argc, char **argv);

/* OPERATIONS */
void	sa(t_dlst *a);
void	sb(t_dlst *b);
void	ss(t_dlst *a, t_dlst *b);
void	pa(t_dlst **a, t_dlst **b);
void	pb(t_dlst **a, t_dlst **b);
void	ra(t_dlst *a);
void	rb(t_dlst *b);
void	rr(t_dlst *a, t_dlst *b);
void	rra(t_dlst *a);
void	rrb(t_dlst *b);
void	rrr(t_dlst *a, t_dlst *b);

#endif