CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilib/libft -fsanitize=address -g
SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRC = server.c banner.c
CLIENT_SRC = client.c

SERVER_OBJS = ${SERVER_SRC:.c=.o}
CLIENT_OBJS = ${CLIENT_SRC:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all: ${SERVER_NAME} ${CLIENT_NAME}

lib/libft/lib_ft.a:
	make -C lib/libft

${SERVER_NAME}: lib/libft/lib_ft.a ${SERVER_OBJS}
		${CC} ${CFLAGS} ${SERVER_OBJS} -o ${SERVER_NAME} -L./lib/libft -lft

${CLIENT_NAME}: lib/libft/lib_ft.a ${CLIENT_OBJS}
		${CC} ${CFLAGS} ${CLIENT_OBJS} -o ${CLIENT_NAME} -L./lib/libft -lft

fclean: clean
		rm -rf ${SERVER_NAME}
		rm -rf ${CLIENT_NAME}
		make fclean -C lib/libft

clean:
		rm -rf ${SERVER_OBJS}
		rm -rf ${CLIENT_OBJS}
		make clean -C lib/libft

re:	fclean all

.PHONY: all clean fclean re