NAME = fractol

CC = clang

FLAGS = -g -Wall -Werror -Wextra -Iinclude

GLFW = -ldl -lglfw -pthread -lm

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./MLX42

MLX = $(MLX_PATH)/libmlx42.a

FILES =	change_zoom\
		color_change\
		color\
		draw\
		fractol\
		info\
		init\
		julia_fract\
		key_controls\
		mouse_controls\
		parse\
		utils\

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(GLFW) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

all: $(NAME)

clean: 
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all

.PHONY = all clean fclean re libft