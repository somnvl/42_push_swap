/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:30:26 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/04 01:30:26 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	flen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	flen = size - dlen - 1;
	if (dlen >= size)
		return (size + slen);
	while (src[i] && flen)
	{
		dst[dlen + i] = src[i];
		i++;
		flen--;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
