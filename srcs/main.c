/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 18:52:15 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

/* OPERATIONS */
int	main(int argc, char **argv)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parsing(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		ft_printf("Error\n");
	else
	{
		tmp_a = stack_a;
		tmp_b = stack_b;
		pb(&stack_b, &stack_a, 0);
		while (tmp_a)
		{
			if (tmp_b)
			{
				ft_printf("%d  %d\n", tmp_a->content, tmp_b->content);
				tmp_b = tmp_b->next;
			}
			else
				ft_printf("%d    \n", tmp_a->content);
			tmp_a = tmp_a->next;
		}
		free_list(stack_a);
		free_list(stack_b);
	}
}

/* PARSING */
// int	main(int argc, char **argv)
// {
// 	t_list	*tmp;
// 	t_list	*stack_a;

// 	stack_a = parsing(argc, argv);
// 	if (!stack_a)
// 		ft_printf("Error\n");
// 	else
// 	{
// 		tmp = stack_a;
// 		while (tmp)
// 		{
// 			ft_printf("%d\n", tmp->content);
// 			tmp = tmp->next;
// 		}
// 	}
// 	free_list(stack_a);
// 	return (0);
// }