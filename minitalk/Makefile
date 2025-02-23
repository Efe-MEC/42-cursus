SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

FT_PRINTF_PATH=ft_printf
FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -l ftprintf -I $(FT_PRINTF_PATH)

NAME = minitalk

$(NAME): $(SERVER) $(CLIENT)

all: $(NAME)

$(SERVER): $(FT_PRINTF) $(SERVER).c
	$(CC) $(CFLAGS) $(SERVER).c -o $(SERVER) $(FT_PRINTF_LIB_FLAGS)

$(CLIENT): $(FT_PRINTF) $(CLIENT).c
	$(CC) $(CFLAGS) $(CLIENT).c -o $(CLIENT) $(FT_PRINTF_LIB_FLAGS)

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_PATH)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(FT_PRINTF) $(SERVER_BONUS).c
	$(CC) $(CFLAGS) $(SERVER_BONUS).c -o $(SERVER_BONUS) $(FT_PRINTF_LIB_FLAGS)

$(CLIENT_BONUS): $(FT_PRINTF) $(CLIENT_BONUS).c
	$(CC) $(CFLAGS) $(CLIENT_BONUS).c -o $(CLIENT_BONUS) $(FT_PRINTF_LIB_FLAGS)

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_PATH)

clean:
	make -s -C $(FT_PRINTF_PATH) clean

fclean:	clean
	$(RM) $(SERVER) $(CLIENT) $(FT_PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus