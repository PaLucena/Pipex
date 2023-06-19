# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 16:02:09 by palucena          #+#    #+#              #
#    Updated: 2023/06/19 12:57:32 by palucena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME = pipex.a
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = $(addsuffix .c $(FILES))
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

# ------------  DIRECTORIES/PATHS  ------------------------------------------- #
LIBFT_PATH = ./libft
OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./inc

# ------------  SOURCE FILES  ------------------------------------------------ #
FILES = pipex.c\
		pipex_utils.c

# ------------  FLAGS  ------------------------------------------------------- #
CC =		gcc
RM =		rm -rf
CFLAGS =	-Wall -Werror -Wextra
LIB =		ar rcs

# ------------  RULES  ------------------------------------------------------- #
$(NAME): $(OBJS)
	@ make -C $(LIBFT_PATH)
	cp $(LIBFT) ./$@
	$(LIB) $@ $(OBJS)
	@ echo "		Pipex compiled!!\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/pipex.h
	@ echo "\n	-------- Compiling program... --------"		
	mkdir -p $(OBJ_PATH)
	$(LIB) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

all: $(NAME)

clean:
	@ $(RM) $(OBJS) $(OBJ_PATH)
	make clean -C $(LIBFT_PATH)
	@ echo "\n	Deleting objects\n"
		
fclean: clean
	@ echo "\n	Deleting everything!!\n"
	@ $(RM) $(NAME)
	

re: fclean all

.PHONY: re all clean fclean