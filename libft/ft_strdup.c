/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:00 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/15 17:52:31 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		lgt;
	int		i;

	lgt = ft_strlen(s);
	dest = malloc(sizeof(char) * lgt + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (lgt > i)
	{
		dest[i] = s[i];
		i++;
	}
	dest[lgt] = 0;
	return (dest);
}
