/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:31:03 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/23 21:34:49 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	db_lstadd_front(t_dlst **lst, t_dlst *new)
{
	new->next = *lst;
	*lst = new;
}

t_dlst	*db_lstnew(void *content)
{
	t_dlst	*lst;

	lst = malloc(sizeof(t_dlst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

