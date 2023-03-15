# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 10:29:42 by ddyankov          #+#    #+#              #
#    Updated: 2023/01/23 12:24:13 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = server client

SOURCE_SERVER = server.c

SOURCE_CLIENT = client.c

SOURCE_S_B = server_bonus.c

SOURCE_C_B = client_bonus.c

OBJ_SERVER = $(SOURCE_SERVER:.c=.o)

OBJ_CLIENT = $(SOURCE_CLIENT:.c=.o)

B_OBJ_S = $(SOURCE_S_B:.c=.o)

B_OBJ_C = $(SOURCE_C_B:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_SERVER) $(OBJ_CLIENT)
	@make --directory libft
	@cc $(CFLAGS) $(OBJ_SERVER) --include-dir libft/libft.a -o server
	@cc $(CFLAGS) $(OBJ_CLIENT) --include-dir libft/libft.a -o client

bonus: $(B_OBJ_S) $(B_OBJ_C)
	@make --directory libft
	@cc $(CFLAGS) $(B_OBJ_S) --include-dir libft/libft.a -o server_bonus
	@cc $(CFLAGS) $(B_OBJ_C) --include-dir libft/libft.a -o client_bonus

clean:
	@make fclean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f server client server_bonus client_bonus *.o

re: fclean all
