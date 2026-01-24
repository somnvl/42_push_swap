/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+              */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/25 19:11:20 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_dlst *lst)
{
	t_dlst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static int	already_sorted(t_dlst *a)
{
	t_dlst	*current;

	if (!a || !a->next)
		return (1);
	current = a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	final_rotate(t_dlst **a)
{
	int	len;
	int	pos;

	len = db_lstsize(*a);
	pos = find_min(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < len)
			rra(a);
	}
}

static void	turk_sort(int size, t_dlst **a, t_dlst **b)
{
	phase_a(size, a, b);
	sort_three(a);
	phase_b(a, b);
	final_rotate(a);
}

int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	int		size;

	a = parsing(argc, argv);
	b = NULL;
	if (argc < 2)
		return (free_list(a), 0);
	if (!a)
		return (free_list(a), ft_printf("Error\n"), 1);
	if (already_sorted(a))
		return (free_list(a), 0);
	normalize(a);
	size = db_lstsize(a);
	if (size <= 5)
		low_sort(size, &a, &b);
	else
		turk_sort(size, &a, &b);
	return (free_list(a), free_list(b), 0);
}
