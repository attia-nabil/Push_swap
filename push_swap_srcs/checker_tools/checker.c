/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:04 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:06 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	eval_ins(t_stack *obj, char *ins)
{
	if (!ft_strncmp(ins, "sa\n", 4))
		sa(obj, 0);
	else if (!ft_strncmp(ins, "sb\n", 4))
		sb(obj, 0);
	else if (!ft_strncmp(ins, "ss\n", 4))
		ss(obj, 0);
	else if (!ft_strncmp(ins, "ra\n", 4))
		ra(obj, 0);
	else if (!ft_strncmp(ins, "rb\n", 4))
		rb(obj, 0);
	else if (!ft_strncmp(ins, "rr\n", 4))
		rr(obj, 0);
	else if (!ft_strncmp(ins, "rra\n", 4))
		rra(obj, 0);
	else if (!ft_strncmp(ins, "rrb\n", 4))
		rrb(obj, 0);
	else if (!ft_strncmp(ins, "rrr\n", 4))
		rrr(obj, 0);
	else if (!ft_strncmp(ins, "pa\n", 4))
		pa(obj, 0);
	else if (!ft_strncmp(ins, "pb\n", 4))
		pb(obj, 0);
	else
		show_err_message(obj, NULL, NULL, ERROR_MSG);
}

static int	is_sorted(t_stack *obj)
{
	obj->tmp = obj->a;
	if (obj->b_size)
		return (FALSE);
	while (obj->tmp->next)
	{
		if (*(int *)obj->tmp->data > *(int *)obj->tmp->next->data)
			return (FALSE);
		obj->tmp = obj->tmp->next;
	}
	return (TRUE);
}

static void	check(t_stack *obj)
{
	char	*ins;

	ins = get_next_line(STDIN_FILENO);
	while (ins)
	{
		eval_ins(obj, ins);
		free(ins);
		ins = get_next_line(STDIN_FILENO);
	}
	free(ins);
	if (is_sorted(obj))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_stack	*obj;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	obj = stack_init();
	args_reader(obj, ac, av);
	check(obj);
	free_all(obj, NULL, NULL);
	exit(EXIT_SUCCESS);
}
