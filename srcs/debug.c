/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:52:15 by so                #+#    #+#             */
/*   Updated: 2026/01/25 18:38:56 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Print single stack showing values and indices.
*/
void	print_stack(t_dlst *lst, char name)
{
	ft_printf("Stack %c: ", name);
	while (lst)
	{
		ft_printf("%d(%d)", lst->content, lst->index);
		if (lst->next)
			ft_printf(" -> ");
		lst = lst->next;
	}
	ft_printf("\n");
}

/*
** Print both stacks A and B for debugging.
*/
void	print_stacks(t_dlst *a, t_dlst *b)
{
	ft_printf("----- STACKS -----\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	ft_printf("------------------\n");
}
