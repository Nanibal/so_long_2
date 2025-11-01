# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#  Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+     #
#   By: nayala <nayala@student.42madrid.com>       #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-04-11 09:13:12 by nayala            #+#    #+#             #
#   Updated: 2025-04-11 09:13:12 by nayala           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

PRINT_DIR = ft_print
PRINT_OBJ = $(PRINT_DIR)/ft_printf.o $(PRINT_DIR)/ft_util.o $(PRINT_DIR)/ft_print_format.o

GNL_DIR = get_next_line
GNL_OBJ = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

all:  $(PRINT_OBJ) $(GNL_OBJ) $(NAME)

$(PRINT_OBJ):
	$(MAKE) -C $(PRINT_DIR)

$(GNL_OBJ):
	$(MAKE) -C $(GNL_DIR)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(AR) $(NAME) $(PRINT_OBJ)
	$(AR) $(NAME) $(GNL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(PRINT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
