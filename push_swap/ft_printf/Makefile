# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 14:26:13 by mehcakir          #+#    #+#              #
#    Updated: 2025/02/02 17:13:03 by mehcakir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c\
			ft_printchar.c\
			ft_printstr.c\
			ft_printnbr.c\
			ft_printptr.c\
			ft_printuint.c\
			ft_printhex.c

OBJS	=	$(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY: all clean fclean re