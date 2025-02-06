# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 14:58:26 by frbranda          #+#    #+#              #
#    Updated: 2024/07/25 13:56:06 by frbranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = client.c server.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

RM = rm -f
AR = ar rcs

# Library Path
LIBFT_DIR = Libft

# Library Name
LIBFT = $(LIBFT_DIR)/libft.a

# All Target
all: client server

# Build client executable
client: client.o $(LIBFT)
	$(CC) $(FLAGS) -o client client.o -L$(LIBFT_DIR) -lft
	@echo "----------------- client created"

# Build server executable
server: server.o $(LIBFT)
	$(CC) $(FLAGS) -o server server.o -L$(LIBFT_DIR) -lft
	@echo "----------------- server created"

# Object Compilation
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

# Compile Libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean
clean:
	$(RM) $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "----------------- OBJECTS deleted"

# Full Clean
fclean: clean
	$(RM) client server
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "----------------- client and server deleted"

# Rebuild Target
re: fclean all

# Phony Targets
.PHONY: all clean fclean re