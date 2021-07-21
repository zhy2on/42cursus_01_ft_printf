# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 17:52:28 by jihoh             #+#    #+#              #
#    Updated: 2021/07/18 17:52:29 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

CC			= gcc
CFLAG		= -Wall -Wextra -Werror
RM			= rm -f
LIBC		= ar -cr

SRCS		=	./ft_printf.c \
				./ft_print.c

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all