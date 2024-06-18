/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:17:52 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:08 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	destlgt;
	size_t	srclgt;

	destlgt = ft_strlen(dst);
	srclgt = ft_strlen(src);
	if (siz <= destlgt)
		return (siz + srclgt);
	i = 0;
	j = ft_strlen(dst);
	while (src[i] && i < siz - destlgt - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (destlgt + srclgt);
}
