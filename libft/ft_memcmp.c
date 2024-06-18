/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:53:55 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:22:27 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ss1;
	unsigned const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (ss1[i] == ss2[i] && (i + 1 < n))
		i++;
	return (ss1[i] - ss2[i]);
}
/*
#include <stdio.h>

int main(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s, sCpy, 4));
}*/