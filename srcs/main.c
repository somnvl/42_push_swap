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

static int	is_sorted(t_dlst *a)
{
    t_dlst  *current;

    if (!a || !a->next)
        return (1);
    current = a;
    while (current->next)
    {
        if (current->content > current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}

int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	int		size;

	a = parsing(argc, argv);
	b = NULL;
	if (!a)
		return (free_list(a), free_list(b), ft_printf("Error\n"), 1);
	// normalize(a);
	if (is_sorted(a))
		return (free_list(a), free_list(b), 0);
	size = db_lstsize(a);
	if (size <= 5)
		ft_printf("low_sort\n"); // low_sort(size, &a, &b);
	else
		ft_printf("turkish_algo\n"); // turkish_algo(a, b);
	return (free_list(a), free_list(b), 0);
}
