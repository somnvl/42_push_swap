/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/21 22:11:22 by somenvie         ###   ########.fr       */
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
	// t_list	*stack_b;

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
	// free_list(stack_b);
}
