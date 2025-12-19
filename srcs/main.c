/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 00:41:25 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst = NULL;
	
	if (argc == 1 || !parsing_digits(argc, argv))
		ft_printf("Error\n");
	else
	{
		lst = lst_creator(argc, argv);
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
}

// should support normal and quoted args at the same time ?
// is empty "" supported ?

// SPLIT
	// not working with the first arg is quoted
	// need to skip empty args

// LST
	// atoi each content and filter INT MIN and MAX
	// check for duplicata