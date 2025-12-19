/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:14:52 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/19 23:53:37 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_spliter(char **res, char const *s, char c, int nb)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == c)
			i = j + 1;
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == 0))
		{
			res[nb] = malloc(sizeof(char) * (j - i + 2));
			if (!res[nb])
			{
				while (nb >= 0)
					free(res[nb--]);
				return (free(res), 0);
			}
			ft_strlcpy(res[nb], (s + i), j - i + 2);
			nb++;
		}
		j++;
	}
	res[nb] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!ft_spliter(res, s, c, 0))
		return (NULL);
	return (res);
}
