/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:45 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/19 21:46:37 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*mem;
	int		i;

	mem = NULL;
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			mem = str + i;
		i++;
	}
	if (str[i] == (char) c)
		mem = str + i;
	return (mem);
}
