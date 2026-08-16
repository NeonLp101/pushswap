# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/20 15:46:37 by jihchoi           #+#    #+#              #
#    Updated: 2026/06/08 18:46:47 by lernst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF     = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

SRC = push_swap.c \
      stack_init.c \
      ops_swap_push.c \
	  ops_swap_push2.c \
      ops_rotate.c \
	  ops_rotate2.c \
      validation.c \
      indexing.c \
      complex.c \
      medium.c \
      simple.c \
      stack_utils.c \
      strategy.c \
      bench.c \
      bench_utils.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
