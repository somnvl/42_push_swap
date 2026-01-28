/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:58:08 by so                #+#    #+#             */
/*   Updated: 2026/01/28 18:28:08 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_op(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

static int	exec_op(char *op, t_dlst **a, t_dlst **b)
{
	if (check_op(op, "sa\n"))
		return (sa(a), 1);
	if (check_op(op, "sb\n"))
		return (sb(b), 1);
	if (check_op(op, "ss\n"))
		return (ss(a, b), 1);
	if (check_op(op, "pa\n"))
		return (pa(a, b), 1);
	if (check_op(op, "pb\n"))
		return (pb(a, b), 1);
	if (check_op(op, "ra\n"))
		return (ra(a), 1);
	if (check_op(op, "rb\n"))
		return (rb(b), 1);
	if (check_op(op, "rr\n"))
		return (rr(a, b), 1);
	if (check_op(op, "rra\n"))
		return (rra(a), 1);
	if (check_op(op, "rrb\n"))
		return (rrb(b), 1);
	if (check_op(op, "rrr\n"))
		return (rrr(a, b), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	char	*line;

	a = parsing(argc, argv);
	b = NULL;
	if (argc < 2)
		return (free_list(a), 0);
	if (!a)
		return (free_list(a), write(2, "Error\n", 6), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!exec_op(line, &a, &b))
			return (free(line), free_list(a), free_list(b),
				write(2, "Error\n", 6), 1);
		free(line);
		line = get_next_line(0);
	}
	if (b == NULL && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(line), free_list(a), free_list(b), 0);
}
