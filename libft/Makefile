# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 20:32:54 by jihchoi           #+#    #+#              #
#    Updated: 2026/05/20 16:41:29 by lernst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_calloc.c \
      ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c ft_strjoin.c \
      ft_atoi.c ft_tolower.c ft_toupper.c ft_itoa.c \
      ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_lstnew.c  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
