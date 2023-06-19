# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 16:02:09 by palucena          #+#    #+#              #
#    Updated: 2023/06/19 13:58:11 by palucena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME = pipex.a
LIBFT = libft/libft.a

# ------------  SOURCE FILES  ------------------------------------------------ #
FILES = pipex.c\
		pipex_utils.c

OBJ = $(FILES:.c=.o)

# ------------  FLAGS  ------------------------------------------------------- #
CC =		gcc
RM =		rm -rf
CFLAGS =	-Wall -Werror -Wextra
LIB =		ar rcs

# ------------  RULES  ------------------------------------------------------- #
$(NAME): $(OBJ)
	@ echo "\n	-------- Compiling program... --------"	
	@ $(LIB) $(NAME) $(OBJ)
	@ make -C libft/
	@ echo "		Pipex compiled!!\n"

$(OBJ): $(FILES)
	@ $(CC) $(CFLAGS) -c $(FILES)

all: $(NAME)

clean:
	@ $(RM) $(OBJ)
	@ make -C libft/ clean
		
fclean: clean
	@ echo "\n	Deleting everything!!\n"
	@ $(RM) $(NAME) $(LIBFT)
	@ make -C libft/ clean
	

re: fclean all

.PHONY: re all clean fclean