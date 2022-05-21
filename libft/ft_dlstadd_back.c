/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:32:32 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:32:34 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
	else
		*dlst = new;
}
