/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 18:21:43 by somenvie         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*stack_a;

	stack_a = parsing(argc, argv);
	if (!stack_a)
		ft_printf("Error\n");
	else
	{
		tmp = stack_a;
		while (tmp)
		{
			ft_printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
	}
	free_list(stack_a);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;
// 	t_list	*stack_a;
// 	t_list	*stack_b;

// 	stack_b = NULL;
// 	stack_a = parsing(argc, argv);
// 	if (!stack_a)
// 	{
// 		ft_printf("Error\n");
// 		free_list(stack_a);
// 		return (1);
// 	}

// 	tmp_a = stack_a;
// 	tmp_b = stack_b;
// 	while (tmp_a || tmp_b->next)
// 	{
// 		ft_printf("%d  %d\n", tmp_a->content, tmp_b->content);
// 		tmp_a = tmp_a->next;
// 		if (tmp_b->next)
// 			tmp_b = tmp_b->next;
// 		else
// 			tmp_b->content = NULL;
// 	}
// 	free_list(stack_a);
// 	free_list(stack_b);
// 	return (0);
// }