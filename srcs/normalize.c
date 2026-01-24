/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/24 03:37:09 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dlst	*find_min_unindexed(t_dlst *a)
{
	t_dlst	*min;

	min = NULL;
	while (a)
	{
		if (a->index == -1)
		{
			if (!min || a->content < min->content)
				min = a;
		}
		a = a->next;
	}
	return (min);
}

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