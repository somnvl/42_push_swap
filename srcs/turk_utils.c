/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:05:48 by so                #+#    #+#             */
/*   Updated: 2026/01/28 17:11:44 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Return absolute value of an integer.
*/
int	abs_i(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*
** Update each node position (0-based) according to its place in the stack.
** Used for cost computation during reinsertion from stack B.
*/
void	update_pos(t_dlst *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s->pos = i++;
		s = s->next;
	}
}

/*
** Convert a node position into a signed rotation cost for a stack of length len.
** Returns the minimal number of moves to bring position 'pos' to the top:
** - positive => rotate (ra/rb) 'pos' times,
** - negative => reverse rotate (rra/rrb) (len - pos) times.
*/
int	cost_to_top_len(int len, int pos)
{
	if (len <= 1 || pos <= 0)
		return (0);
	if (pos <= len / 2)
		return (pos);
	return (pos - len);
}

/*
** Return the position in A with the lowest rotation cost to reach the top.
** Used to choose which element to move first during phase A.
*/
int	best_pos_global(t_dlst *a, int len_a)
{
	int	i;
	int	best_pos;
	int	best_abs;
	int	cost;

	i = 0;
	best_pos = 0;
	best_abs = INT_MAX;
	while (a)
	{
		if (i <= len_a / 2)
			cost = i;
		else
			cost = i - len_a;
		if (abs_i(cost) < best_abs)
		{
			best_abs = abs_i(cost);
			best_pos = i;
		}
		a = a->next;
		i++;
	}
	return (best_pos);
}
