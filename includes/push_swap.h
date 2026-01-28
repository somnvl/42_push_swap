/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:31 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 20:25:30 by so               ###   ########.fr       */
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
void	sa(t_dlst **a, int print);
void	sb(t_dlst **b, int print);
void	ss(t_dlst **a, t_dlst **b, int print);
void	pa(t_dlst **a, t_dlst **b, int print);
void	pb(t_dlst **a, t_dlst **b, int print);
void	ra(t_dlst **a, int print);
void	rb(t_dlst **b, int print);
void	rr(t_dlst **a, t_dlst **b, int print);
void	rra(t_dlst **a, int print);
void	rrb(t_dlst **b, int print);
void	rrr(t_dlst **a, t_dlst **b, int print);

/* EARLY EXIT */
void	low_sort(int size, t_dlst **a, t_dlst **b);
void	sort_three(t_dlst **a);
void	sort_four(t_dlst **a, t_dlst **b);
void	sort_five(t_dlst **a, t_dlst **b);
int		find_min(t_dlst *s);

/* TURK ALGO */
void	turk_sort(int size, t_dlst **a, t_dlst **b);
void	pick_cheapest(t_dlst *a, t_dlst *b, int *ca, int *cb);
void	apply_cheapest(t_dlst **a, t_dlst **b, int ca, int cb);

void	apply_a(t_dlst **a, int *ca);
void	update_pos(t_dlst *s);
int		cost_to_top_len(int len, int pos);
int		best_pos_global(t_dlst *a, int len_a);
int		abs_i(int x);

/* CHECKER */
void	free_list(t_dlst *lst);
int		already_sorted(t_dlst *a);
int		check_op(const char *s1, const char *s2);
int		exec_op(char *op, t_dlst **a, t_dlst **b);

/* DEBUG */
void	print_stack(t_dlst *lst, char name);
void	print_stacks(t_dlst *a, t_dlst *b);

#endif