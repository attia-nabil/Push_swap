/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:44 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:47:16 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_rotate(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		*head = ft_dlstlast(*head);
		(*head)->next = ft_dlstfirst(*head);
		(*head)->next->prev = *head;
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	rra(t_stack *obj, int flag)
{
	if (r_rotate(&obj->a, obj->a_size) && flag)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *obj, int flag)
{
	if (r_rotate(&obj->b, obj->b_size) && flag)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *obj, int flag)
{
	if (r_rotate(&obj->a, obj->a_size)
		&& r_rotate(&obj->b, obj->b_size) && flag)
		ft_putendl_fd("rrr", 1);
}
