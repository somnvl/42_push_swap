/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 20:40:07 by somenvie         ###   ########.fr       */
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
	t_list	*a;
	t_list	*b;
	t_list	*tmpa;
	t_list	*tmpb;

	a = parsing(argc, argv);
	b = NULL;
	if (!a)
		ft_printf("Error\n");
	else
	{
		ra(a);
		tmpa = a;
		tmpb = b;
		ft_printf("-----\n");
		while (tmpa || tmpb)
		{
			if (tmpb)
			{
				ft_printf("%d   %d\n", tmpa->content, tmpb->content);
				tmpb = tmpb->next;
			}
			else
				ft_printf("%d   -\n", tmpa->content);
			tmpa = tmpa->next;
		}
		free_list(a);
		free_list(b);
	}
}
