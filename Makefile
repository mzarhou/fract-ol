ODIR = obj
SRCS = main.c
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -Imlx
RM = rm -rf

NAME = prog

${ODIR}/%.o: %.c
	@mkdir -p ${@D}
	CC ${CC_FLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
