/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:25 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:47:22 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*obj;

	obj = (t_stack *)malloc(sizeof(t_stack));
	if (!obj)
		show_err_message(obj, NULL, NULL, ALLOC_ERR);
	obj->a = NULL;
	obj->b = NULL;
	obj->tmp = NULL;
	obj->a_size = 0;
	obj->b_size = 0;
	return (obj);
}

void	free_all(t_stack *obj, char *rec, char **list)
{
	int	i;

	if (!obj)
		return ;
	if (obj->a)
		ft_dlstclear(&obj->a, free);
	if (obj->b)
		ft_dlstclear(&obj->b, free);
	if (list)
	{
		i = -1;
		while (list[++i])
			free(list[i]);
		free(list);
	}
	if (rec)
		free(rec);
	free(obj);
}
