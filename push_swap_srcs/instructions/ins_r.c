/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:38 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:41 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		(*head) = (*head)->next;
		(*head)->prev->prev = ft_dlstlast(*head);
		(*head)->prev->prev->next = (*head)->prev;
		(*head)->prev->prev->next->next = NULL;
		(*head)->prev = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	ra(t_stack *obj, int flag)
{
	if (rotate(&obj->a, obj->a_size) && flag)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *tab, int flag)
{
	if (rotate(&tab->b, tab->b_size) && flag)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *obj, int flag)
{
	if (rotate(&obj->a, obj->a_size) && rotate(&obj->b, obj->b_size) && flag)
		ft_putendl_fd("rr", 1);
}
