CC = cc
FLAGS = -Wall -Wextra -Werror -Lft_printf -lftprintf
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SERVER_OBJ = server.o
CLIENT_OBJ = client.o ft_atoi.o
BONUS_SERVER = bonus_server
BONUS_CLIENT = bonus_client
BONUS_SERVER_OBJ = server_bonus.o
BONUS_CLIENT_OBJ = client_bonus.o ft_atoi.o
PRINTF = ft_printf/libftprintf.a



all: $(PRINTF) $(CLIENT)  $(SERVER) 

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(PRINTF) $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_SERVER_OBJ)
	$(CC) $(FLAGS) $(BONUS_SERVER_OBJ) -o $(BONUS_SERVER)

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJ)
	$(CC) $(FLAGS) $(BONUS_CLIENT_OBJ) -o $(BONUS_CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

$(SERVER): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)  $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ) ft_printf/*.o 
fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(PRINTF) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all clean fclean re