# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#  Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+     #
#   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-06-02 08:43:58 by nayala            #+#    #+#             #
#   Updated: 2025-06-02 08:43:58 by nayala           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC = main.c map_parser.c game.c graphics.c utils.c validate_map.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

GREEN = \033[0;32m 
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $@
	@echo "$(GREEN)$(NAME) compilado correctamente$(NC)"
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)✗ Objetos y libft limpios$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)✗ $(NAME) y libft eliminados$(NC)"

re: fclean all

.PHONY: all clean fclean re bonus