/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:31:03 by somenvie          #+#    #+#             */
/*   Updated: 2026/01/28 16:36:31 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Append a node at the end of a doubly-linked list.
** If the list is empty, the new node becomes the head.
** Otherwise, we link the current last node to the new one and set
** the new node's prev pointer, keeping next = NULL as the tail.
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
** Allocate and initialize a new doubly-linked list node.
** Sets content, resets pointers, and initializes index to -1
** (later filled by normalize).
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
** Return the last node of the doubly-linked list.
** Used to append at the end and to traverse from the tail when needed.
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
** Return the number of nodes in the doubly-linked list.
** Simple linear traversal counting each element.
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
