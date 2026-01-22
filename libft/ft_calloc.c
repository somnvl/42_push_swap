/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:11 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/06 19:05:11 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			len;
	unsigned char	*ptr;

	i = 0;
	len = size * nmemb;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
