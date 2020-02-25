# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 20:53:35 by asbai-el          #+#    #+#              #
#    Updated: 2020/01/22 20:53:37 by asbai-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
SRCS = ft_atoi.c \
		ft_itoa.c \
		ft_printf.c \
		ft_strlen.c \
		parse_flag.c \
		print_int.c \
		ft_strdup.c \
		write_space.c \
		write_zero.c \
		print_string.c \
		print_percent.c \
		print_car.c \
		ft_isdigit.c \
		ft_isalpha.c \
		countdigit.c \
		ft_putnstr.c \
		ft_utoa.c \
		print_unsint.c \
		ft_max.c \
		print_hex.c \
		write_hex.c \
		len_hex.c \
		print_pointer.c \
		len_pointer.c \
		write_pointer.c \
		print_unsint2.c \
		print_int2.c \
		print_hex2.c


OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
