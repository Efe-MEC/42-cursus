# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 13:50:29 by mehcakir          #+#    #+#              #
#    Updated: 2025/02/02 17:12:54 by mehcakir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		= main.c arg_utils.c check_1.c check_2.c\
			  find.c init.c sort.c cost.c target.c\
			  op.c op_a.c op_b.c op_ab.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF	= $(FT_PRINTF_DIR)/libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -g
RM			= rm -rf

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re