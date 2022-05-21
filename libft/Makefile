# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nattia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 23:42:58 by nattia            #+#    #+#              #
#    Updated: 2022/05/14 23:43:00 by nattia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c 	\
			ft_memset.c 	\
			ft_bzero.c  	\
			ft_memcpy.c 	\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c 	\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c 	\
			ft_memcmp.c 	\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			get_next_line.c	\
			get_next_line_utils.c


BONUS	=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_dlstnew.c		\
			ft_dlstadd_front.c	\
			ft_dlstsize.c		\
			ft_dlstlast.c		\
			ft_dlstfirst.c		\
			ft_dlstadd_back.c	\
			ft_dlstdelone.c		\
			ft_dlstclear.c		\
			ft_dlstiter.c		\
			ft_dlstmap.c

S_OBJ	=	$(SRC:.c=.o)
B_OBJ	=	$(BONUS:.c=.o)
HEADER	=	../include/libft.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM 		=	rm -f
AR		=	ar crs
NAME	=	libft.a

.PHONY	: all bonus clear fclear re

all		:	$(NAME)

$(NAME)	:	$(S_OBJ) $(HEADER)
	@$(AR) $@ $(S_OBJ)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	Library was created ✅\033[0m\n"

bonus	:	$(S_OBJ) $(B_OBJ) $(HEADER)
	@$(AR) $(NAME) $(S_OBJ) $(B_OBJ)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	Library was created ✅\033[0m\n"

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c -I ../include $< -o $(<:.c=.o)

clean	:
	@echo "\n\033[2;32m\033[3m[+]\033[2;37m	Cleaning ✅\033[0m\n"
	@$(RM) $(S_OBJ)
	@$(RM) $(B_OBJ)

fclean	:	clean
	@echo "\033[2;32m\033[3m[+]\033[2;37m	Remove files ✅\033[0m\n"
	@$(RM) $(NAME)

re		:	fclean all
