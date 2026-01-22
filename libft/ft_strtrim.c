/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:52:45 by somenvie          #+#    #+#             */
/*   Updated: 2025/11/06 20:52:45 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkchar(char const c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_empty(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	j = len - 1;
	while (ft_checkchar(s1[i], set))
		i++;
	if (i == len)
		return (ft_empty());
	while (ft_checkchar(s1[j], set))
		j--;
	str = malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + i), (j - i + 2));
	return (str);
}
