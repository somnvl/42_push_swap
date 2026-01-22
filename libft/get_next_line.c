/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:57:27 by somenvie          #+#    #+#             */
/*   Updated: 2025/12/17 00:07:34 by somenvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gnl_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == DELIM)
			return (1);
		i++;
	}
	return (0);
}

static char	*get_stash(char *stash)
{
	char	*str;

	if (!stash)
		return (NULL);
	str = gnl_strdup_stash(stash);
	return (free(stash), stash = NULL, str);
}

static char	*read_file(int fd, char *stash)
{
	int		eof;
	char	*buffer;

	eof = 1;
	while (eof)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		eof = read(fd, buffer, BUFFER_SIZE);
		if (eof == 0 || eof == -1)
			return (free(buffer), stash);
		buffer[eof] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin(stash, buffer);
		if (gnl_check(buffer) == 1)
			return (free(buffer), stash);
		free(buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd] || !*stash[fd])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = gnl_strdup_line(stash[fd]);
	stash[fd] = get_stash(stash[fd]);
	return (line);
}
