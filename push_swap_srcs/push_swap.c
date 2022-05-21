/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:44:02 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:44:04 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*obj;

	if (ac < 2)
		usage();
	obj = stack_init();
	args_reader(obj, ac, av);
	if (unordered_list(obj->a))
		sort_list(obj);
	free_all(obj, NULL, NULL);
	exit(EXIT_SUCCESS);
}
