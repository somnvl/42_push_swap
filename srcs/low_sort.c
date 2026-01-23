/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:15 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/23 22:13:41 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_two(t_dlst **a, t_dlst **b)
{
	
}

static void	sort_three(t_dlst **a, t_dlst **b)
{
	
}

static void	sort_four(t_dlst **a, t_dlst **b)
{
	
}

static void	sort_five(t_dlst **a, t_dlst **b)
{
	
}

void	low_sort(int size, t_dlst **a, t_dlst **b)
{
	if (size == 2)
		sort_two(a, b);
	else if (size == 3)
		sort_three(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
