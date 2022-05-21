/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:33:15 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:33:17 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*newlst;

	if (!dlst || !f)
		return (NULL);
	newlst = NULL;
	while (dlst)
	{
		new = ft_dlstnew(f(dlst->data));
		if (!new)
		{
			ft_dlstclear(&newlst, del);
			return (NULL);
		}
		ft_dlstadd_back(&newlst, new);
		dlst = dlst->next;
	}
	return (newlst);
}
