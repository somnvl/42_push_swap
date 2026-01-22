/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:17:46 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/17 00:08:36 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

char	*gnl_strdup_line(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != DELIM && s[i])
		i++;
	dest = malloc(i + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != DELIM)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = s[i];
	dest[i + 1] = '\0';
	return (dest);
}

char	*gnl_strdup_stash(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	while (s[i] && s[i] != DELIM)
		i++;
	if (!s[i])
		return (NULL);
	i++;
	len = 0;
	while (s[i + len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	j = 0;
	while (j < len)
	{
		dest[j] = s[i + j];
		j++;
	}
	return (dest);
}

char	*gnl_strdup(char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (dest == NULL)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
