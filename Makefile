ODIR = obj
SRCS = ${wildcard src/*.c} ${wildcard src/**/*.c}
OBJS = ${patsubst %.c, ${ODIR}/%.o, ${SRCS}}
INC = src
CC = cc
CC_FLAGS = -Wall -Werror -Wextra -Imlx
RM = rm -rf

NAME = fract-ol

${ODIR}/%.o: %.c
	@mkdir -p ${@D}
	${CC} ${CC_FLAGS} -c $< -o $@ -I ${INC}

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${ODIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re bonus all
