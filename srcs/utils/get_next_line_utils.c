/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:51 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/25 19:30:38 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * ft_strlen(src) + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	stashcheck(char *stash, int sz)
{
	long	i;

	i = 0;
	if (!stash || sz == 0)
		return (1);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*getcontent(char *tmp, char *buffer, char *stash)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		stash[i] = tmp[i];
		i++;
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		stash[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		stash[i + j] = buffer[j];
		j++;
	}
	stash[i + j] = 0;
	free(tmp);
	return (stash);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
