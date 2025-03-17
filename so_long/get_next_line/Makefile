# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 19:01:44 by mehcakir          #+#    #+#              #
#    Updated: 2025/03/13 20:59:49 by mehcakir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a

SRCS =	get_next_line.c

OBJS = $(SRCS:%.c=%.o)


CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

$(NAME): $(OBJS)
	cc $(CFLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re