/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 16:52:46 by so               ###   ########.fr       */
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
	int				pos;
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
void	sort_three(t_dlst **a);
void	sort_four(t_dlst **a, t_dlst **b);
void	sort_five(t_dlst **a, t_dlst **b);
int		find_min(t_dlst *s);

/* TURKISH ALGO */
void	turk_sort(int size, t_dlst **a, t_dlst **b);
void	pick_cheapest(t_dlst *a, t_dlst *b, int *ca, int *cb);
void	apply_cheapest(t_dlst **a, t_dlst **b, int ca, int cb);

void	apply_a(t_dlst **a, int *ca);
void	update_pos(t_dlst *s);
int		cost_to_top_len(int len, int pos);
int		best_pos_global(t_dlst *a, int len_a);
int		abs_i(int x);

/* DEBUG */
void	print_stack(t_dlst *lst, char name);
void	print_stacks(t_dlst *a, t_dlst *b);

#endif