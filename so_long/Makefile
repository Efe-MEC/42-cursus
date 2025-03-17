# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehcakir <mehcakir@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 18:32:28 by mehcakir          #+#    #+#              #
#    Updated: 2025/03/14 23:20:01 by mehcakir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c exit.c check.c check_utils.c images.c draw.c move.c map.c key.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF	  = $(FT_PRINTF_DIR)/libftprintf.a

GET_DIR		= get_next_line
GET			= $(GET_DIR)/get_next_line.a

MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GET_DIR) -I$(MLX_DIR)
RM			= rm -rf

$(NAME): $(LIBFT) $(FT_PRINTF) $(GET) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GET_DIR) -lget_next_line -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)
	
$(GET):
	$(MAKE) -C $(GET_DIR)

$(MLX):
	$(MAKE) -s -C $(MLX_DIR)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GET_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re