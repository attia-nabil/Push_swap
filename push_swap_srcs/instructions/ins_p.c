/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:31 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:33 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_dlist **dst, t_dlist **src, int *d_size, int *s_size)
{
	if (!*src)
		return (FALSE);
	if (*s_size > 0)
	{
		if (*s_size == 1)
		{
			(*src)->next = *dst;
			*dst = *src;
			*src = NULL;
		}
		else
		{
			*src = (*src)->next;
			(*src)->prev->next = *dst;
			*dst = (*src)->prev;
			(*src)->prev = NULL;
		}
		if (*d_size)
			(*dst)->next->prev = *dst;
		(*s_size)--;
		(*d_size)++;
		return (TRUE);
	}
	return (FALSE);
}

void	pa(t_stack *obj, int flag)
{
	if (push(&obj->a, &obj->b, &obj->a_size, &obj->b_size) && flag)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack *obj, int flag)
{
	if (push(&obj->b, &obj->a, &obj->b_size, &obj->a_size) && flag)
		ft_putendl_fd("pb", 1);
}
