/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:53 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:55 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		if (size == 2)
		{
			*head = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev->next = NULL;
			(*head)->prev = NULL;
		}
		else
		{
			*head = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			(*head)->prev->next = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev->prev = *head;
			(*head)->prev = NULL;
		}
		return (TRUE);
	}
	return (FALSE);
}

void	sa(t_stack *obj, int flag)
{
	if (swap(&obj->a, obj->a_size) && flag)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *obj, int flag)
{
	if (swap(&obj->b, obj->b_size) && flag)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *obj, int flag)
{
	if (swap(&obj->a, obj->a_size) && swap(&obj->b, obj->b_size) && flag)
		ft_putendl_fd("ss", 1);
}
