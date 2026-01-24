/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/24 17:59:46 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_dlst
{
	struct s_dlst	*prev;
	int				content;
	int				index;
	struct s_dlst	*next;
}					t_dlst;

/* LST */
void	free_list(t_dlst *lst);
void	db_lstadd_back(t_dlst **lst, t_dlst *new);
t_dlst	*db_lstnew(int content);
t_dlst	*db_lstlast(t_dlst *lst);
int		db_lstsize(t_dlst *lst);

/* PARSING */
t_dlst	*parsing(int argc, char **argv);
t_dlst	*lst_creator(int argc, char **argv);

/* NORMALIZE */
void	normalize(t_dlst *lst);

/* OPERATIONS */
void	sa(t_dlst **a);
void	sb(t_dlst **b);
void	ss(t_dlst **a, t_dlst **b);
void	pa(t_dlst **a, t_dlst **b);
void	pb(t_dlst **a, t_dlst **b);
void	ra(t_dlst **a);
void	rb(t_dlst **b);
void	rr(t_dlst **a, t_dlst **b);
void	rra(t_dlst **a);
void	rrb(t_dlst **b);
void	rrr(t_dlst **a, t_dlst **b);

/* EARLY EXIT */
void	low_sort(int size, t_dlst **a, t_dlst **b);

/* TURKISH ALGO */
void	turk_sort();

/* DEBUG */
void	print_stack(t_dlst *lst, char name);
void	print_stacks(t_dlst *a, t_dlst *b);

#endif