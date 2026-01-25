/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/25 18:42:54 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find first unindexed node with minimum content value.
*/
static t_dlst	*find_min_unindexed(t_dlst *a)
{
	t_dlst	*tmp;
	t_dlst	*min;

	tmp = a;
	min = NULL;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			if (!min || tmp->content < min->content)
				min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

/*
** Assign normalized indices [0..n-1] to stack based on sorted content order.
*/
void	normalize(t_dlst *a)
{
	t_dlst	*tmp;
	t_dlst	*min;
	int		i;

	tmp = a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	i = 0;
	min = find_min_unindexed(a);
	while (min)
	{
		min->index = i;
		i++;
		min = find_min_unindexed(a);
	}
}
