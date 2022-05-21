/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:43:19 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:43:21 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usage(void)
{
	ft_putstr_fd("\n\e[33m➜\e[0m", 1);
	ft_putstr_fd("  Usage: \e[32m./push_swap\e[0m <list of numbers>\n\n", 1);
	exit(EXIT_FAILURE);
}

void	show_err_message(t_stack *obj, char *rec, char **list, char *msg)
{
	ft_putendl_fd(msg, 2);
	free_all(obj, rec, list);
	exit(EXIT_FAILURE);
}

int	just_spaces(char *s)
{
	while (*s)
		if (*s++ != ' ')
			return (FALSE);
	return (TRUE);
}
