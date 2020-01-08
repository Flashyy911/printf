# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:17:54 by asbai-el          #+#    #+#              #
#    Updated: 2020/01/04 19:54:24 by asbai-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  src/ft_printf.c \
      libft/ft_strchrn.c libft/ft_atoi.c\
      libft/ft_isspace.c libft/ft_isdigit.c\
      src/ft_getargs.c libft/ft_strjoin.c\
      libft/ft_strlen.c libft/ft_strdup.c\
      src/ft_gettype.c libft/ft_strlcpy.c\
      libft/ft_itoa.c libft/ft_strjoinfree.c\
      libft/ft_substr.c libft/ft_calloc.c\
      libft/ft_bzero.c libft/ft_memset.c\
      src/converters/ft_char_to_string.c\
      libft/ft_size_t_itoa.c src/ft_flagstructinit.c\
      src/ft_isflag.c src/flagschecker/ft_miuscheck.c\
      src/flagschecker/ft_zerocheck.c\
      src/flagschecker/ft_pointcheck.c\
      src/ft_minusflip.c\
      src/converters/ft_hex_to_string.c\
      src/converters/ft_min_hex_to_string.c\
      src/ft_specialcases.c\
      src/converters/ft_adress_to_string.c\
      libft/ft_putchar.c\
      libft/ft_putchar_fd.c\
      libft/ft_strcmp.c\
      libft/ft_strdupfree.c\
      src/flagschecker/ft_isprintfstring.c\
      src/flagschecker/ft_isprintfint.c\
       src/converters/ft_size_t_to_hex.c\
      src/flagschecker/ft_isprintfchar.c\
      src/converters/ft_p_handler.c\
	  src/ft_char_special_case.c

INC = headers/ft_printf.h
OBJ = $(SRC:.c=.o)

FLAG = -Wextra -Werror -Wall

all:$(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAG)  -c $< -o $@ -I$(INC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
