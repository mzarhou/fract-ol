ODIR = obj
SRCS = src/events/ft_on_destroy.c \
	src/events/ft_on_key_down.c \
	src/events/ft_on_mouse_down.c \
	src/events/ft_on_mouse_move.c \
	src/events/ft_register_events.c \
	src/main.c \
	src/sets/ft_burning_ship_iterate.c \
	src/sets/ft_julia_set_iterate.c \
	src/sets/ft_mandelbrot_iterate.c \
	src/utils/ft_atoi.c \
	src/utils/ft_map.c \
	src/utils/ft_mlx_pixel_put.c \
	src/utils/ft_pixel_coloring.c
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
