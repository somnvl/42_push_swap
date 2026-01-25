/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:35:11 by so                #+#    #+#             */
/*   Updated: 2026/01/25 21:45:06 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Calculate chunk size based on input size (size/5, size/10, size/15).
*/
int	chunk_step(int size)
{
	if (size <= 100)
		return (size / 5);
	if (size <= 500)
		return (size / 5);
	return (size / 15);
}

/*
** Initialize first chunk range [0, step-1], cap at max index.
*/
void	chunk_init(int *start, int *end, int step, int max)
{
	*start = 0;
	*end = step - 1;
	if (*end > max)
		*end = max;
}

/*
** Check if any elements from current chunk remain in stack A.
*/
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

/*
** Advance to next chunk range, cap at max index if needed.
*/
void	chunk_next(int *start, int *end, int step, int max)
{
	*start = *end + 1;
	*end = *start + step - 1;
	if (*end > max)
		*end = max;
}
