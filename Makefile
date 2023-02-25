NAME = minitalk

CLIENT = client
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:.c=.o)

SERVER = server
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENTOBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENTOBJ) $(LIBFT)

$(SERVER): $(SERVEROBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVEROBJ) $(LIBFT)

clean:
	rm $(CLIENTOBJ) $(SERVEROBJ)
	rm ./libft/*.o

fclean : clean
	rm client server
	rm ./libft/libft.a

re : fclean all

.PHONY : all clean flcean re
