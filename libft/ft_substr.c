/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:37:52 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/06 19:37:52 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
	}
	else
	{
		i = ft_strlen(s + start);
		if (i > len)
			i = len;
		str = ((char *)malloc(sizeof(char) * (i + 1)));
		if (!str)
			return (NULL);
		str[i] = 0;
		while (i-- > 0)
			str[i] = s[i + start];
	}
	return (str);
}
