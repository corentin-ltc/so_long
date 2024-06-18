/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:22:11 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:29:26 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*strd;

	if (!dest && !src)
		return (NULL);
	str = (char *)dest;
	strd = (char *)src;
	i = 0;
	while (n > i)
	{
		str[i] = strd[i];
		i++;
	}
	return (dest);
}
