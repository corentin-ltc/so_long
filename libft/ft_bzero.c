/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:18:59 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/25 13:45:51 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (n > i)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	char str[] = "Test Ok ca marche ?";

	ft_bzero(str, 5);
	printf("%s\n", str);
}*/