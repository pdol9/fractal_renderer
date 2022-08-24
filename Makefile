# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 17:12:33 by pdolinar          #+#    #+#              #
#    Updated: 2022/07/18 19:03:07 by pdolinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
INC			=	include
HEADER		=	$(INC)/fractol.h
HEADER_L	=	$(LIBFT_DIR)/$(INC)/libft.h
INC_L		=	$(LIBFT_DIR)/include
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
RM		= rm -rf

SRC_DIR		=	src/
OBJ_DIR		=	build/
SRC = main.c utils.c init.c msg.c sets.c features.c colors.c
OBJ	= $(SRC:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:.c=.o)))
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

CLEAR = \033[0m
PR = \033[1;35m
GR = \033[1;32m

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@make -s -C ./mlx
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)
	@echo "$(GR)>> compiling ..."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER) $(HEADER_L)
	$(CC) $(CFLAGS) -I $(INC) -I $(INC_L) -Imlx -c $< -o $@

$(LIBFT):
	@$(MAKE) all -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	$(MAKE) clean -s -C ./mlx
	@echo "$(PR)All object files deleted$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PR)$(NAME) deleted$(CLEAR)"

norm:
	norminette $(SRC_DIR) $(INC)

re:	fclean all

.PHONY: all clean fclean re
