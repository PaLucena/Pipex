NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src/
SRC = pipex.c pipex_utils.c
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR_B = src/
SRC_B = pipex_bonus.c pipex_utils.c
OBJ_B = $(addprefix $(OBJ_DIR), $(SRC_B:.c=.o))


all: libft $(NAME)

bonus: libft $(NAME_BONUS)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/*.o
	@ echo "\n\t\t\033[32mPipex compiled!\n"

$(NAME_BONUS): $(OBJ_B)
	@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_B) libft/*.o
	@ echo "\n\t\t\033[32mPipex_bonus compiled!\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_B)%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(FLAGS) -c $< -o $@

libft:
	@make -C libft/

clean:
	@ $(RM) -r $(OBJ_DIR)
	@ make -C libft/ clean
	@ echo "\n\t\t\033[31mEverything is clean!\n"

fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@ make -C libft/ fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus libft clean fclean re re_bonus