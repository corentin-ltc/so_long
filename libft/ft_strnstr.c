/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:29:43 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/17 15:50:18 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenght;

	lenght = ft_strlen(little);
	if (lenght == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && len > i)
	{
		j = 0;
		while (big[i + j] && big[i + j] == little[j] && len > i + j)
			j++;
		if (j == lenght)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int main(int argc, const char **argv)
{
	printf("%s\n", ft_strnstr(argv[1], argv[2], 10));
}*/