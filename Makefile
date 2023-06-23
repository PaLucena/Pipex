NAME= pipex

CC= gcc
FLAGS=	-Wall -Wextra -Werror 
RM=		rm -rf

SRCS=	pipex.c pipex_utils.c


OBJS= $(SRCS:.c=.o)

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@

all:	libft	${NAME}

${NAME}:	${OBJS}
	@ echo "\n		Compiling pipex...\n"
	@ ${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a

libft:
	@ make -C libft/ all

clean:
	@ ${RM} *.o */*.o

fclean:		clean
	@ echo "\n		Cleaning...\n"
	@ ${RM} ${NAME}
	@ ${RM} libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re libft
