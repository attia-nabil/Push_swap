/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:32:41 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:32:43 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		new->next = *dlst;
		(*dlst)->prev = new;
		*dlst = new;
	}
	else
		*dlst = new;
}
