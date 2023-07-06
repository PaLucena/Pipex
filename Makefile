NAME =			pipex
NAME_BONUS =	pipex_bonus

CC= gcc
FLAGS=	-Wall -Wextra -Werror
RM=		rm -rf

SRCS=	pipex.c utils.c

SRCS_BONUS=	pipex_bonus.c utils.c


OBJS= $(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

all:	libft	${NAME}

${NAME}:	${OBJS}
	@ echo "\n		\033[33mCompiling pipex...\n"
	@ ${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a

bonus:	libft	${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
	@ echo "\n		\033[33mCompiling pipex_bonus...\n"
	@ ${CC} ${FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} libft/libft.a

libft:
	@ make -C libft/ all

clean:
	@ echo "\n		\033[31mCleaning...\n"
	@ ${RM} *.o */*.o

fclean:		clean
	@ ${RM} ${NAME} ${NAME_BONUS}
	@ ${RM} libft/libft.a

re:			fclean all

re_bonus:	fclean bonus

.PHONY:		all bonus libft clean fclean re re_bonus
