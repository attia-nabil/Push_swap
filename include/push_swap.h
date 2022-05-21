/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoutaou <ymoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:32:25 by ymoutaou          #+#    #+#             */
/*   Updated: 2022/03/02 14:26:43 by ymoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ERROR_MSG "\n\e[31mError\e[0m\n"
# define ALLOC_ERR "\n\e[31mAllocation failed!\e[0m\n"
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*tmp;
	int		a_size;
	int		b_size;
}	t_stack;

// global_tools
void	usage(void);
void	show_err_message(t_stack *obj, char *rec, char **list, char *msg);
void	args_reader(t_stack *obj, int ac, char **av);
int		just_spaces(char *s);
t_stack	*stack_init(void);
void	free_all(t_stack *obj, char *rec, char **list);

// sort_tools
int		unordered_list(t_dlist *tmp);
void	put_index(t_stack *obj);
void	sort_list(t_stack *obj);
void	big_sort(t_stack *obj);
void	small_sort(t_stack *obj);

// instructions
void	sa(t_stack *obj, int flag);
void	sb(t_stack *obj, int flag);
void	ss(t_stack *obj, int flag);
void	ra(t_stack *obj, int flag);
void	rb(t_stack *obj, int flag);
void	rr(t_stack *obj, int flag);
void	rra(t_stack *obj, int flag);
void	rrb(t_stack *obj, int flag);
void	rrr(t_stack *obj, int flag);
void	pa(t_stack *obj, int flag);
void	pb(t_stack *obj, int flag);

#endif