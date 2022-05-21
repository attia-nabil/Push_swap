/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:11 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:14 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*new_data(t_stack *obj, char **list, int dt)
{
	int			*data;

	data = (int *)malloc(sizeof(int));
	if (!data)
		show_err_message(obj, NULL, list, ALLOC_ERR);
	*data = dt;
	return (data);
}

static int	args_checker(char *rec)
{
	int	i;
	int	exp1;
	int	exp2;

	i = -1;
	while (rec[++i])
	{
		exp1 = (!(rec[i] == '-' && ft_isdigit(rec[i + 1]))
				&& !(rec[i] == '+' && ft_isdigit(rec[i + 1]))
				&& !ft_isdigit(rec[i]) && rec[i] != ' ');
		exp2 = ((ft_isdigit(rec[i]) && rec[i + 1] == '-')
				|| (ft_isdigit(rec[i]) && rec[i + 1] == '+'));
		if (exp1 || exp2)
			return (FALSE);
	}
	return (TRUE);
}

static int	seen_before(char **list, char *nbr, int pos)
{
	int	i;

	i = -1;
	while (++i < pos)
		if (ft_atoi(list[i]) == ft_atoi(nbr))
			return (TRUE);
	return (FALSE);
}

static void	add_to_stack(char *rec, char **list, t_stack *obj)
{
	int	i;
	int	j;
	int	s;
	int	index;

	s = -1;
	while (list[++s])
		if (seen_before(list, list[s], s))
			show_err_message(obj, rec, list, ERROR_MSG);
	index = s - 1;
	i = -1;
	while (list[++i])
	{
		j = -1;
		while (list[++j])
			if (ft_atoi(list[i]) < ft_atoi(list[j]) && i != j)
				index--;
		ft_dlstadd_back(&obj->a, ft_dlstnew(new_data(obj, list, index)));
		index = s - 1;
	}
	obj->a_size = ft_dlstsize(obj->a);
	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
}

void	args_reader(t_stack *obj, int ac, char **av)
{
	char	**list;
	char	*rec;
	char	*tmp;
	int		r;

	r = 0;
	rec = ft_strdup("");
	while (++r < ac)
	{
		if (just_spaces(av[r]) || av[r][0] == '\0'
			|| ft_atoi(av[r]) > INT_MAX || ft_atoi(av[r]) < INT_MIN)
			show_err_message(obj, rec, NULL, ERROR_MSG);
		tmp = rec;
		rec = ft_strjoin(tmp, av[r]);
		free(tmp);
		tmp = rec;
		rec = ft_strjoin(tmp, " ");
		free(tmp);
	}
	if (!args_checker(rec))
		show_err_message(obj, rec, NULL, ERROR_MSG);
	list = ft_split(rec, ' ');
	add_to_stack(rec, list, obj);
	free(rec);
}
