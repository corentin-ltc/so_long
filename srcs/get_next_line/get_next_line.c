/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:14:03 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:07 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*resetline(char *buffer, char *stash)
{
	long		i;
	long		j;
	char		*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		tmp[j] = buffer[i + j];
		j++;
	}
	tmp[j] = 0;
	buffer = ft_strcpy(buffer, tmp);
	free(tmp);
	return (stash);
}

void	ft_bzero(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

char	*gnl3(char *stash, int *ptr_sur_sz, char *buffer, int fd)
{
	char	*tmp;

	tmp = ft_strdup(stash);
	free(stash);
	if (!tmp)
		return (NULL);
	*ptr_sur_sz = read(fd, buffer, BUFFER_SIZE);
	if (*ptr_sur_sz < 0)
	{
		ft_bzero(buffer);
		free(tmp);
		return (NULL);
	}
	buffer[*ptr_sur_sz] = 0;
	stash = malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(tmp) + 2));
	if (!stash)
	{
		free(tmp);
		return (NULL);
	}
	stash = getcontent(tmp, buffer, stash);
	return (stash);
}

int	gnl2(int *ptr_sur_sz, char *buffer, int fd)
{
	*ptr_sur_sz = read(fd, buffer, BUFFER_SIZE);
	if (*ptr_sur_sz < 0)
	{
		ft_bzero(buffer);
		return (0);
	}
	buffer[*ptr_sur_sz] = 0;
	if (*ptr_sur_sz == 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1] = {0};
	int				sz;
	char			*stash;
	int				*ptr_sur_sz;

	ptr_sur_sz = &sz;
	sz = 1;
	if (fd >= FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[0])
	{
		if (!gnl2(ptr_sur_sz, buffer, fd))
			return (NULL);
	}
	stash = ft_strdup(buffer);
	if (!stash)
		return (NULL);
	while (!stashcheck(stash, sz))
	{
		stash = gnl3(stash, ptr_sur_sz, buffer, fd);
		if (!stash)
			return (NULL);
	}
	return (resetline(buffer, stash));
}
