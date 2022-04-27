# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:16:49 by sthitiku          #+#    #+#              #
#    Updated: 2022/04/27 16:43:27 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# SRCS = ft_printf.c ft_alpha.c ft_number.c ft_numint.c libft.c
SRCS = ft_printf.c ft_printf_utils.c ft_print_int.c ft_print_space.c ft_print_zero.c \
		ft_print_minus.c ft_print_chars.c ft_print_base.c ft_flag_handle.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re