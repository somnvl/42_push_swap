/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:13:02 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/20 01:51:13 by somenvie         ###   ########.fr       */
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

// LST
	// atoi each content and filter INT MIN and MAX
	// check for duplicata