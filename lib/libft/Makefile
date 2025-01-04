CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
CFILES = ft_isdigit.c\
	 ft_atoi.c\


OBJS = ${CFILES:.c=.o}

BONUSOBJS = ${BONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus: ${BONUSOBJS} ${OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUSOBJS}

fclean:	clean
	rm -rf ${NAME}

clean:
	rm -rf ${OBJS} ${BONUSOBJS}

re:	fclean all

.PHONY: all clean fclean re
