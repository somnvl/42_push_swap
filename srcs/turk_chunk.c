/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:35:11 by so                #+#    #+#             */
/*   Updated: 2026/01/25 15:58:15 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	chunk_step(int size)
{
	if (size <= 100)
		return (size / 5);
	if (size <= 500)
		return (size / 10);
	return (size / 15);
}

void	chunk_init(int *start, int *end, int step, int max)
{
	*start = 0;
	*end = step - 1;
	if (*end > max)
		*end = max;
}

int	chunk_left(t_dlst *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (1);
		a = a->next;
	}
	return (0);
}

void	chunk_next(int *start, int *end, int step, int max)
{
	*start = *end + 1;
	*end = *start + step - 1;
	if (*end > max)
		*end = max;
}
