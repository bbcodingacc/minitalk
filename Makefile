NAME = minitalk

CLIENT = client
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:.c=.o)

SERVER = server
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:.c=.o)

SERVER_BONUS = server_bonus
SERVER_BONUS_SRC = server_bonus.c
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRC = client_bonus.c
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENTOBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENTOBJ) $(LIBFT)

$(SERVER): $(SERVEROBJ)
	@make -C ./libft 
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVEROBJ) $(LIBFT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) 
	
$(SERVER_BONUS): $(SERVER_BONUS_OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(LIBFT)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(LIBFT)

clean:
	rm $(CLIENTOBJ) $(SERVEROBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	rm ./libft/*.o

fclean : clean
	rm $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	rm ./libft/libft.a

re : fclean all

.PHONY : all bonus clean flcean re
