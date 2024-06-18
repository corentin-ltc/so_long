/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:30:44 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/20 14:36:14 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstart(char const *s, unsigned int start)
{
	if (ft_strlen(s) <= start)
		return (0);
	return (1);
}

static char	*ft_substr2(const char *s, unsigned int start, size_t sizem)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * sizem + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((sizem > i && s[start + i] != 0))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	sizem;

	if (!s)
		return (NULL);
	if (!checkstart(s, start))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	i = 0;
	sizem = 0;
	while (len > 0 && s[start + i])
	{
		sizem++;
		i++;
		len--;
	}
	return (ft_substr2(s, start, sizem));
}
/*
#include <stdio.h>

int main (void)
{
	printf("%s\n", ft_substr("tripouille", 100, 1));
}*/