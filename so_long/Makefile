NAME = so_long
SRCS = srcs/main.c srcs/map.c srcs/map_utils.c srcs/graphics.c \
		srcs/events.c srcs/assets.c srcs/events_utils.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I includes/ -I libft/ -I /home/es/minilibx/

LIBFT = libft/libft.a
MLX_LIB = -L/home/es/minilibx -lmlx
MLX_INC = -I/home/es/minilibx

CC = gcc
CFLAGS = $(INCLUDES) $(MLX_INC)
LIBS = $(MLX_LIB) -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re