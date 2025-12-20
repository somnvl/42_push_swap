/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 16:15:19 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_list(t_list *lst)
{
	t_list	*tmp;
	
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
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
			ft_printf("%s\n", tmp->content);
			tmp = tmp->next;
		}
		free_list(lst);
	}
}

// LST
	// create ft that atol each numbers and return if limits reached
	// check for duplicata