# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:27:12 by frbranda          #+#    #+#              #
#    Updated: 2024/07/31 14:11:15 by frbranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_striteri.c ft_strmapi.c ft_split.c \
			ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putnbr_pf.c \
			ft_getlen_pf.c ft_putnbr_base.c ft_putnbr_base_p.c \
			ft_strjoin_mini.c \

BSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c\

OBJECT = $(SOURCES:.c=.o)

OBJB = $(BSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(AR) $(NAME) $(OBJECT)
	@echo "----------------- $(NAME) created"

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(NAME) $(OBJB)
	$(AR) $(NAME) $(OBJB)
	@echo "----------------- BONUS created"

clean:
	$(RM) $(OBJECT) $(OBJB)
	@echo "----------------- OBJECT deleted"

fclean: clean
	$(RM) $(NAME)
	@echo "----------------- $(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re bonus