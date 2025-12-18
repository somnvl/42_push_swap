/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 00:12:34 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/18 16:47:05 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	digits_only(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != ' ')) 
				return (1);
			// if ((argv[i][j] < '0' || argv[i][j] > '9') 
			// 	&& (argv[i][j] != ' ') 
			// 	&& (argv[i][j] != '+' && argv[i][j] != '-'))
			// 	return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// if ((argv[i][j] == '+' || argv[i][j] == '-') && ft_isdigit(argv[i][j + 1] == 1))
			// 	return (1);

// t_list	lst_init(int argc, char **argv)
// {
// 	// ft_lstnew
// 	// split args into nodes
// }

int	main(int argc, char **argv)
{
	/* DIGITS ONLY */
	if (argc == 1 || digits_only(argc, argv) == 1)
		ft_printf("Error\n");
	else
		ft_printf("OK\n");
	
	// lst = lst_init(argc, argv);
		// generate my list with atoi (which filter min & max)
	/* < INT_MIN || > INT_MAX */
	/* DUPLICATA */
}


// atoi into list args -> filter min && max
		// check duplicata
		// algorithm


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


