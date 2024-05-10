CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c fractol.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

MLX42_PATH = /path/to/mlx42

MLX42_FLAGS = -L$(MLX42_PATH) -lmlx42 -lm -lXext -lX11

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re