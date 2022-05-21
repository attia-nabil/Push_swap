/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:39:43 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:39:45 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_elm;

	if (!lst || !f)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		n_elm = ft_lstnew(f(lst->data));
		if (!n_elm)
		{
			ft_lstdelone(n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, n_elm);
		lst = lst->next;
	}
	return (n_lst);
}
