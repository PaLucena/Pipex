NAME= pipex
CC= gcc
FLAGS= -Wall -Wextra -Werror 
RM= rm -rf
SRCS=      pipex.c pipex_utils.c
SRCS=      pipex.c pipex_utils.c
SRCS=      pipex.c pipex_utils.c
                          
OBJS= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a

all:		libft ${NAME}

bonus:		all

libft:
			@ make -C libft/
clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


