NAME = minitalk
CLIENT = client.c 
SERVER = server.c
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(libft) $(SERVER) $(CLIENT)
	@make -C ./libft
	$(CC) $(CFLAGS) -o server $(SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o client $(CLIENT) $(LIBFT)

clean:
	rm 
	rm ./libft/*.o

flcean : clean



.PHONY : all clean flcean re
