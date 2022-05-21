/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:33:24 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:33:26 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	len;

	if (!dlst)
		return (0);
	len = 0;
	while (dlst && ++len)
		dlst = dlst->next;
	return (len);
}
