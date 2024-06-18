/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:17:25 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:29:56 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*str;
	char	*strs;

	if (!dest && !src)
		return (NULL);
	str = (char *)dest;
	strs = (char *)src;
	i = 0;
	while (src < dest && n > 0)
	{
		str[n - 1] = strs[n - 1];
		n--;
	}
	while (n > 0)
	{
		str[i] = strs[i];
		i++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char test[15] = "123123123";

	ft_memmove(test + 2, test, 10);
	printf("%s\n", test);
}*/
