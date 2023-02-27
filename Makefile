NAME = minitalk

CLIENT = client
CLIENTSRC = client.c
CLIENTOBJ = client.o

SERVER = server
SERVERSRC = server.c
SERVEROBJ = server.o

SERVER_BONUS = server_bonus
SERVER_BONUS_SRC = server_bonus.c
SERVER_BONUS_OBJ = server_bonus.o

CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRC = client_bonus.c
CLIENT_BONUS_OBJ = client_bonus.o

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEF_COLOR = \033[0m
CYAN = \033[1;36m
RED = \033[1;91m
GREEN = \033[92m

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENTOBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENTOBJ) $(LIBFT)
	@echo "$(CYAN)MINITALK:$(GREEN) Client is ready"

$(SERVER): $(SERVEROBJ)
	@make -C ./libft 
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVEROBJ) $(LIBFT)
	@echo "$(CYAN)MINITALK:$(GREEN) Server is ready"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(SERVER_BONUS) $(CLIENT_BONUS) 
	
$(SERVER_BONUS): $(SERVER_BONUS_OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(LIBFT)
	@echo "$(CYAN)MINITALK:$(GREEN) Server_bonus is ready"

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(LIBFT)
	@echo "$(CYAN)MINITALK: $(GREEN)Client_bonus is ready"

%_bonus.o: %_bonus.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(CLIENTOBJ) $(SERVEROBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@$(RM) ./libft/*.o
	@echo "$(CYAN)MINITALK:$(GREEN) Object files deleted"
	@echo "$(RED)LIBFT:$(GREEN) Object files cleaned"

fclean : clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(RM) ./libft/libft.a
	@echo "$(CYAN)MINITALK:$(GREEN) Object files and program cleaned"
	@echo "$(RED)LIBFT:$(GREEN) Object files and program cleaned"

re : fclean all
	@echo "$(CYAN)MINITALK:$(GREEN) Programs deleted"

.PHONY : all bonus clean flcean re
