# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nattia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:44:08 by nattia            #+#    #+#              #
#    Updated: 2022/05/14 23:44:10 by nattia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_SRCS		=	push_swap_srcs/global_tools/args_tools.c	\
				push_swap_srcs/global_tools/error_tools.c	\
				push_swap_srcs/global_tools/stack_tools.c	\
				push_swap_srcs/sort_tools/sort_tools.c		\
				push_swap_srcs/instructions/ins_p.c		\
				push_swap_srcs/instructions/ins_r.c		\
				push_swap_srcs/instructions/ins_rr.c	\
				push_swap_srcs/instructions/ins_s.c		\
				push_swap_srcs/sort_tools/big_sort.c	\
				push_swap_srcs/sort_tools/small_sort.c	\
				push_swap_srcs/push_swap.c

CK_SRCS		=	push_swap_srcs/global_tools/args_tools.c	\
				push_swap_srcs/global_tools/error_tools.c	\
				push_swap_srcs/global_tools/stack_tools.c	\
				push_swap_srcs/instructions/ins_p.c		\
				push_swap_srcs/instructions/ins_r.c		\
				push_swap_srcs/instructions/ins_rr.c	\
				push_swap_srcs/instructions/ins_s.c		\
				push_swap_srcs/checker_tools/checker.c

PS_OBJS		=	$(PS_SRCS:.c=.o)
CK_OBJS		=	$(CK_SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra

NAME		=	push_swap
NAME_B		=	checker
LIB			=	libft/libft.a
HEADER		=	include/push_swap.h

all			:	$(NAME) $(LIB)

$(NAME)		:	$(LIB) $(PS_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) -I include $(PS_OBJS) -o $@
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	push_swap File was created ✅\033[0m\n"

bonus		:	$(NAME_B)

$(NAME_B)	:	$(LIB) $(CK_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) -I include $(CK_OBJS) -o $@
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	checker File was created ✅\033[0m\n"
	
%.o			:	%.c
	@$(CC) $(CFLAGS) -I include -c $< -o $(<:.c=.o)
	

$(LIB)		:
	@make bonus -C libft
	

clean		:
	@make clean -C libft
	@$(RM) $(PS_OBJS)
	@$(RM) $(CK_OBJS)
	
	
fclean		:
	@make fclean -C libft
	@$(RM) $(PS_OBJS)
	@$(RM) $(CK_OBJS)
	@$(RM) $(NAME_B)
	@$(RM) $(NAME)
	

re			:	fclean all

.PHONY		:	all re clean fclean