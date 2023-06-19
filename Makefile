# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 16:02:09 by palucena          #+#    #+#              #
#    Updated: 2023/06/19 12:12:00 by palucena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME = pipex.a
LIBFT = 

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR =	src
HDR_DIR =	hdr
OBJ_DIR =	objs

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS = $(SRC_DIR)/pipex.c\
	$(SRC_DIR)/pipex_utils.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS =	$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS =	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))

# ------------  FLAGS  ------------------------------------------------------- #
CC =		gcc
RM =		rm -rf
CFLAGS =	-Wall -Werror -Wextra
LIB =		ar rcs

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJ): $(SRC_FLS)
	$(CC)$(CFLAGS) -c $(SRC_FLS)

$(OBJ_DIR):
	@ echo "\n	-------- Compiling program... --------"
	

$(NAME): $(OBJS)
	@ $(LIB) $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "		Pipex compiled!!\n"

clean:
	@ $(RM) $(OBJ)
		
fclean: clean
	@ echo "\n	Deleting everything!!\n"
	@ $(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean