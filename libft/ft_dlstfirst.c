/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:32:54 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:32:56 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}
