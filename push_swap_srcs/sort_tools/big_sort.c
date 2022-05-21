/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoutaou <ymoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:53:31 by ymoutaou          #+#    #+#             */
/*   Updated: 2022/03/09 15:56:33 by ymoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_in_parts(t_stack *obj, int part_size)
{
	int	part_nb;
	int	part_tv;
	int	part;

	part_nb = 1;
	part_tv = 0;
	while (obj->a_size)
	{
		part = part_size * part_nb;
		if (*(int *)obj->a->data < part)
		{
			pb(obj, 1);
			if (*(int *)obj->b->data < part - (part_size / 2))
				rb(obj, 1);
			part_tv++;
		}
		else
			ra(obj, 1);
		if (part_tv == part)
			part_nb++;
	}
}

static int	push_next(t_stack *obj, int swap)
{
	if (*(int *)obj->b->data == obj->b_size - 2 && !swap)
	{
		pa(obj, 1);
		return (1);
	}
	return (0);
}

int	smart_rotate(t_stack *obj)
{
	int	pos;
	int	swap;
	int	size;

	pos = 0;
	swap = 0;
	size = obj->b_size;
	obj->tmp = obj->b;
	while (*(int *)obj->tmp->data != size - 1 && ++pos)
		obj->tmp = obj->tmp->next;
	while (*(int *)obj->b->data != size - 1)
	{
		if (!push_next(obj, swap))
		{
			if (pos > size / 2)
				rrb(obj, 1);
			else
				rb(obj, 1);
		}
		else
			swap = 1;
	}
	return (swap);
}

static void	push_back(t_stack *obj)
{
	while (obj->b_size)
	{
		if (smart_rotate(obj))
		{
			pa(obj, 1);
			sa(obj, 1);
		}
		else
			pa(obj, 1);
	}
}

void	big_sort(t_stack *obj)
{
	int	part_size;

	part_size = obj->a_size / 10 + 12;
	push_in_parts(obj, part_size);
	push_back(obj);
}
