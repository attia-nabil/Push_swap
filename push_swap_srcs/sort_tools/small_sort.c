/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoutaou <ymoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:33:32 by ymoutaou          #+#    #+#             */
/*   Updated: 2022/03/02 19:33:39 by ymoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(int *arr)
{
	int	i;

	i = 0;
	while (i < 3 && i + 1 < 3)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	update_arr(t_stack *obj, int *arr)
{
	arr[0] = *(int *)obj->a->data;
	arr[1] = *(int *)obj->a->next->data;
	arr[2] = *(int *)obj->a->next->next->data;
}

static void	sort_3(t_stack *obj)
{
	int	arr[3];

	update_arr(obj, arr);
	while (!is_ordered(arr))
	{
		update_arr(obj, arr);
		if (arr[0] > arr[1] && arr[0] > arr[2])
		{
			ra(obj, 1);
			continue ;
		}
		if (arr[2] < arr[1])
		{
			rra(obj, 1);
			continue ;
		}
		if (arr[0] > arr[1])
		{
			sa(obj, 1);
			break ;
		}
	}
}

static void	sort_4_5(t_stack *obj)
{
	int	size;

	size = obj->a_size;
	while (obj->a && obj->a_size > 3)
	{
		if (*(int *)obj->a->data < (size - 3))
			pb(obj, 1);
		else
			ra(obj, 1);
	}
	sort_3(obj);
	while (obj->b && obj->b_size)
	{
		if (obj->b_size > 1
			&& *(int *)obj->b->data < *(int *)obj->b->next->data)
			rb(obj, 1);
		pa(obj, 1);
	}
}

void	small_sort(t_stack *obj)
{
	if (obj->a_size == 2)
		if (*(int *)obj->a->data > *(int *)obj->a->next->data)
			sa(obj, 1);
	if (obj->a_size == 3)
		sort_3(obj);
	if (obj->a_size == 4 || obj->a_size == 5)
		sort_4_5(obj);
}
