/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/17 17:41:43 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	check_duplicata(int nb, t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (tmp->next)
// 	{
// 		if (nb == tmp->content)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

int	check_digits_only(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || check_digits_only(argc, argv) == 1)
		ft_printf("Error\n");
	else
		ft_printf("OK"); 
//	else
		// atoi into list args -> filter min && max
		// check duplicata
		// algorithm
}

