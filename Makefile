NAME =			pipex
NAME_BONUS =	pipex_bonus

CC= gcc
FLAGS=	-Wall -Wextra -Werror
RM=		rm -rf

SRCS=	pipex.c pipex_utils.c

SRCS_BONUS=	pipex_bonus.c pipex_utils.c


OBJS= $(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

all:	libft	${NAME}

${NAME}:	${OBJS}
	@ echo "\n\t\t\033[32mPipex compiled!\n"
	@ ${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a

bonus:	libft	${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
	@ echo "\n\t\t\033[32mPipex_bonus compiled!\n"
	@ ${CC} ${FLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} libft/libft.a

libft:
	@ make -C libft/ all

clean:
	@ echo "\n\t\t\033[31mCleaning...\n"
	@ ${RM} *.o */*.o

fclean:		clean
	@ ${RM} ${NAME} ${NAME_BONUS}
	@ ${RM} libft/libft.a

re:			fclean all

re_bonus:	fclean bonus

.PHONY:		all bonus libft clean fclean re re_bonus
