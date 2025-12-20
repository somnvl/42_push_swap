/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 02:02:10 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = parsing(argc, argv);
	if (!lst)
		ft_printf("Error\n");
	else
	{
		while (lst)
		{
			ft_printf("%s\n", lst->content);
			lst = lst->next;
		}
	}
}

// PARSING
	// clean lines, norm
	// reread / understand better and opti code
	// check that each ft has it utility ect.. clean and organized code

// LST
	// create ft that atol each numbers and return if limits reached
	// check for duplicata