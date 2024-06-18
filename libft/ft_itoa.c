/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:22:25 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:28:24 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long n)
{
	int	j;

	j = 1;
	if (n < 0)
	{
		n = -n;
		j++;
	}
	while (n > 9)
	{
		n /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	nb;

	nb = (long) n;
	count = ft_countdigits(nb);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[count - 1] = (nb % 10) + '0';
		count--;
		nb /= 10;
	}
	return (str);
}
/*#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(INT_MIN));
//	printf("%s\n",ft_itoa(atoi(argv[1])));
}*/