# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:47:06 by jeandrad          #+#    #+#              #
#    Updated: 2024/06/29 13:47:08 by jeandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name: Fractol
NAME = fractol

# Name: Fractol_bonus
NAME_BONUS = fractol_bonus

# Compiler
CC = clang

# Compiler flags
FLAGS = -g -Wall -Werror -Wextra -Iinclude #-fsanitize=address

# GLFW for MLX42 linux
GLFW = -ldl -lglfw -pthread -lm 

# Source files for libft
LIBFT_PATH = ./libft

#Compiled libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source files for mlx42
MLX_PATH = ./MLX42

#Compiled mlx42
MLX = $(MLX_PATH)/libmlx42.a

# Source files for mandatory
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

# Source files for bonus
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

# Source directory
SRCS_DIR = ./src/

# Source files prepended with directory and appended with .c
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

# Object directory for mandatory source files
OBJS_DIR = ./src/

# Source files prepended with directory and appended with .o
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# Directory for bonus source files
BNS_DIR = ./bonus/

# Source files prepended with directory and appended with .c
SRCS_BNS = $(addprefix $(BNS_DIR), $(addsuffix .c, $(BONUS_FILES)))

# Object directory for bonus source files
BNS_OBJS_DIR = ./bonus/

# Bonus source files prepended with directory and appended with .o
OBJS_BONUS = $(addprefix $(BNS_OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))

# Compile rule
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

# Build rule for mandatory
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(GLFW) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "Fractol created"

# Build rule for bonus
$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(GLFW) $(OBJS_BONUS) $(LIBFT) $(MLX) -o $(NAME_BONUS)
	@echo "Fractol_bonus created"

# Build rule for libft
$(LIBFT):
	@make -C $(LIBFT_PATH) all

# Build rule for mlx42
$(MLX):
	@make -C $(MLX_PATH) all

# Build rule for mandatory
all: $(NAME)

# Build rule for bonus
bonus: $(NAME_BONUS)

# Clean rule
clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

# Fclean rule
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) fclean

# Re rule
re: fclean all

.PHONY = all clean fclean re libft