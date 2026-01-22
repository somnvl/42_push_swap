/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:39:29 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/04 19:39:29 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;

	if (!dest && !src)
		return (NULL);
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		csrc = (char *)src;
		cdest = (char *)dest;
		while (n--)
			cdest[n] = csrc[n];
	}
	return (dest);
}
