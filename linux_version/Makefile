# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 17:12:33 by pdolinar          #+#    #+#              #
#    Updated: 2023/08/23 21:11:03 by pdolinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -O3
RM		:= rm -rf
NAME	:= fractol
INC		:= include
HEADER	:= $(INC)/fractol.h

# libft library
LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a
INC_L     := $(LIBFT_DIR)/$(INC)
HEADER_L  := $(LIBFT_DIR)/$(INC)/libft.h

# MiniLibX library
MLX_DIR   := ./mlx
MLX_FLAGS := -I /usr/X11/include -L /usr/X11/lib -L ./mlx -lmlx -lm -lX11 -lXext -lz

SRC_DIR	:=	src/
OBJ_DIR	:=	build/
SRC := main.c utils.c init.c msg.c sets.c features.c colors.c
OBJ	= $(SRC:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:.c=.o)))

CLEAR := \033[0m
PR := \033[1;35m
GR := \033[1;32m

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(MLX_DIR)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)
	@echo "$(GR)>> compiling ...$(CLEAR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER) $(HEADER_L)
	$(CC) $(CFLAGS) -I $(INC) -I $(INC_L) -Imlx -c $< -o $@

$(LIBFT):
	@$(MAKE) all -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	$(MAKE) clean -s -C $(MLX_DIR)
	@echo "$(PR)All object files removed$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PR)$(NAME) removed$(CLEAR)"

# check source code in regard to the school’s norm
norm:
	norminette $(SRC_DIR) $(INC)

re:	fclean all

.PHONY: all clean fclean re
