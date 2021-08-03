# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 17:52:28 by jihoh             #+#    #+#              #
#    Updated: 2021/08/03 01:54:42 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

CC		= gcc
CFLAG		= -Wall -Wextra -Werror
RM		= rm -f
LIBC		= ar -cr

SRCS		= ./ft_printf.c ./ft_print.c ./ft_print_nbr.c
BSRCS		= ./ft_printf_bonus.c ./ft_print_bonus.c ./ft_print_nbr_bonus.c

OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

bonus : $(BOBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(BOBJS)

clean :
	$(RM) $(OBJS) $(BOBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
