/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:58:08 by so                #+#    #+#             */
/*   Updated: 2026/01/28 21:07:54 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Read and free all remaining lines from stdin until EOF.
** Used to properly clean get_next_line internal buffers
** when the checker exits early on error (pipe mode).
*/
static void	drain_stdin_until_eof(void)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(0);
	}
}

/*
** Print error message, free all allocated resources,
** optionally drain stdin if input is not interactive,
** and return an error code.
*/
static int	error_exit(t_dlst *a, t_dlst *b, char **line)
{
	write(2, "Error\n", 6);
	if (line)
		free(*line);
	if (!isatty(0))
		drain_stdin_until_eof();
	free_list(a);
	free_list(b);
	return (1);
}

/*
** Read operations from stdin and apply them to stacks.
** Returns non-zero if an invalid operation is encountered.
*/
static int	read_and_apply_ops(t_dlst **a, t_dlst **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_op(line, a, b))
			return (error_exit(*a, *b, &line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (0);
}

/*
** Checker entry point.
** Initializes stacks, reads and applies operations,
** then prints OK or KO depending on final state.
*/
int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;

	if (argc < 2)
		return (0);
	a = parsing(argc, argv);
	if (!a)
		return (error_exit(a, NULL, NULL));
	b = NULL;
	if (read_and_apply_ops(&a, &b))
		return (1);
	if (b == NULL && already_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(a);
	free_list(b);
	return (0);
}
