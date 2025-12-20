/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 19:45:00 by somenvie         ###   ########.fr       */
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
	t_list	*lst;
	t_list	*tmp;

	lst = parsing(argc, argv);
	if (!lst)
		ft_printf("Error\n");
	else
	{
		tmp = lst;
		while (tmp)
		{
			ft_printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
	}
	free_list(lst);
}
