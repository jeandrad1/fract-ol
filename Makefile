NAME = fractol

NAME_BONUS = fractol_bonus

CC = clang

FLAGS = -g -Wall -Werror -Wextra -Iinclude -fsanitize=address

GLFW = -ldl -lglfw -pthread -lm 

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./MLX42

MLX = $(MLX_PATH)/libmlx42.a

FILES =	change_zoom\
		color\
		draw\
		fractol\
		info\
		init\
		julia_fract\
		mandelbrot_fract\
		key_controls\
		mouse_controls\
		parse\
		utils\
		exit_error\

BONUS_FILES =	change_zoom_bonus\
		color_change_bonus\
		color_bonus\
		draw_bonus\
		fractol_bonus\
		info_bonus\
		init_bonus\
		julia_fract_bonus\
		mandelbrot_fract_bonus\
		tricorn_fract_bonus\
		key_controls_bonus\
		mouse_controls_bonus\
		parse_bonus\
		utils_bonus\
		exit_error_bonus\

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

BNS_DIR = ./bonus/
SRCS_BNS = $(addprefix $(BNS_DIR), $(addsuffix .c, $(BONUS_FILES)))

BNS_OBJS_DIR = ./bonus/
OBJS_BONUS = $(addprefix $(BNS_OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(GLFW) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(GLFW) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

all: $(NAME)

bonus: $(NAME_BONUS)

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all

.PHONY = all clean fclean re libft