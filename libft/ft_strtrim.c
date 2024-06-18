/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:54:24 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/20 14:36:34 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchar(char c, const char *set);

static size_t	ft_len(const char *s1, const char *set)
{
	size_t		i;
	int			k;
	size_t		endstr;

	endstr = ft_strlen(s1);
	i = 0;
	k = 0;
	while (endstr > 0 && !checkchar(s1[endstr - 1], set))
		endstr--;
	if (endstr == 0)
		return (0);
	while (s1[i] && k == 0)
	{
		if (checkchar(s1[i], set))
		{
			k++;
			return (endstr - i);
		}
		i++;
	}
	return (0);
}

static int	checkchar(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;
	size_t	i;
	int		k;
	size_t	endstr;

	if (!s1)
		return (NULL);
	endstr = ft_strlen(s1);
	len = ft_len(s1, set);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	k = 0;
	while (endstr > 0 && !checkchar(s1[endstr - 1], set))
		endstr--;
	while (s1[++i] && endstr > i && len > 0)
	{
		if (checkchar(s1[i], set) || k > 0)
			dest[k++] = s1[i];
	}
	dest[k] = 0;
	return (dest);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{

	//printf("%s\n", ft_strtrim("ttatatt", "t"));
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
}
*/
