/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:30:26 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/05 22:30:26 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cs;

	i = 0;
	cs = (char) c;
	while (s[i])
	{
		if (s[i] == cs)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cs)
		return ((char *)&s[i]);
	return (NULL);
}
