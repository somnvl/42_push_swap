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

int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	t_dlst	*tmpa;
	t_dlst	*tmpb;

	a = parsing(argc, argv);
	b = NULL;

	if (!a)
		ft_printf("Error\n");
	else
	{
		ft_printf("  OP \n");
		ft_printf("------\n");

		sa(&a);
 
		tmpa = a;
		tmpb = b;

		ft_printf("\nSTACKS \n");
		ft_printf("------\n");

		while (tmpa || tmpb)
		{
			if (tmpb)
			{
				ft_printf("%d    %d\n", tmpa->content, tmpb->content);
				tmpb = tmpb->next;
			}
			else
				ft_printf("%d    \n", tmpa->content);
			tmpa = tmpa->next;
		}

		free_list(a);
		free_list(b);
	}
}
