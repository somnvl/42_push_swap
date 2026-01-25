/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:31:03 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/25 18:41:09 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Add new node to end of doubly-linked list, updating prev/next pointers.
*/
void	db_lstadd_back(t_dlst **lst, t_dlst *new)
{
	t_dlst	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	last = db_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}

/*
** Create new doubly-linked list node with given content, initialize index to -1.
*/
t_dlst	*db_lstnew(int content)
{
	t_dlst	*lst;

	lst = malloc(sizeof(t_dlst));
	if (!lst)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->content = content;
	lst->index = -1;
	return (lst);
}

/*
** Return pointer to last node in doubly-linked list.
*/
t_dlst	*db_lstlast(t_dlst *lst)
{
	t_dlst	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*
** Count total nodes in doubly-linked list.
*/
int	db_lstsize(t_dlst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
