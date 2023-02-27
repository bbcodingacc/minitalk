# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 12:03:07 by mkarabog          #+#    #+#              #
#    Updated: 2023/02/27 05:00:49 by mkarabog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr \
		ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
		ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi \
		ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
		ft_printchar ft_printdecimal ft_printf ft_printhexadec ft_printpercent ft_printstring ft_printunsigned ft_printhexaptr


SRCS = $(addsuffix .c, $(FILE))

OBJS = $(addsuffix .o, $(FILE))

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libft.a

DEF_COLOR = \033[0m
CYAN = \033[1;36m
RED = \033[1;91m
GREEN = \033[92m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(RED)LIBFT:$(GREEN) Object files created"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(RED)LIBFT:$(GREEN) Archive file created"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)LIBFT:$(GREEN) Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)LIBFT:$(GREEN) Object files and program cleaned"

re: fclean $(NAME)
	@echo "$(RED)LIBFT:$(GREEN) The process was repeated"

.PHONY : all clean fclean re