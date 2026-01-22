/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:30:26 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/05 22:30:26 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cs;

	i = 0;
	cs = (char) c;
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == cs)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
