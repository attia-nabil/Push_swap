/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoutaou <ymoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:38:36 by ymoutaou          #+#    #+#             */
/*   Updated: 2022/03/02 19:38:41 by ymoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	unordered_list(t_dlist *tmp)
{
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->data > *(int *)tmp->next->data)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

void	sort_list(t_stack *obj)
{
	if (obj->a_size <= 5)
		small_sort(obj);
	else
		big_sort(obj);
}
