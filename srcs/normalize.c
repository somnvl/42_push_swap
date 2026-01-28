/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 16:38:42 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Find the smallest (by content) node that has not been indexed yet.
** We scan the list and keep the best candidate among nodes with index == -1.
** Returns NULL when all nodes are already indexed.
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
** Normalize stack values into indexes in the range [0..n-1].
** Each node is initially created with index = -1 (in db_lstnew),
** so we can directly assign increasing indexes by repeatedly
** selecting the smallest unindexed node.
*/
void	normalize(t_dlst *a)
{
	t_dlst	*min;
	int		i;

	i = 0;
	min = find_min_unindexed(a);
	while (min)
	{
		min->index = i;
		i++;
		min = find_min_unindexed(a);
	}
}
