/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:06:54 by cle-tort          #+#    #+#             */
/*   Updated: 2024/05/25 19:52:15 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*checkparams(t_list *lst, void *(*f)(void *))
{
	void		*content;
	t_list		*newlst;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	if (!content)
		return (NULL);
	newlst = ft_lstnew(content);
	if (!newlst)
	{
		free(content);
		return (NULL);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*newlst;
	t_list		*tmp;
	void		*content;

	newlst = checkparams(lst, f);
	if (!newlst)
		return (NULL);
	tmp = newlst;
	while (lst->next)
	{
		lst = lst->next;
		content = f(lst->content);
		if (!content)
			return (NULL);
		tmp->next = ft_lstnew(content);
		if (!(tmp->next))
		{	
			free(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (newlst);
}
