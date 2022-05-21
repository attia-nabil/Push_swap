/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:32:45 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:32:47 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	void	*tmp;

	if (!dlst || !del)
		return ;
	while (*dlst)
	{
		del((*dlst)->data);
		tmp = *dlst;
		*dlst = (*dlst)->next;
		free(tmp);
	}
	*dlst = NULL;
}
