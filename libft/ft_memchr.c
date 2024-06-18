/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:19:48 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:37:54 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*str;
	unsigned int		j;

	str = (unsigned char *)s;
	i = 0;
	j = 0;
	while (n > i)
	{
		if (str[i] == (unsigned char) c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
