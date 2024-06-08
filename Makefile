NAME		=	fractol

SRC			=	fracto.c main.c

MLX42_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
				
LIBFT		=	libft/libft.a

MLX42		=	MLX42/libmlx42.a

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

$(MLX42):
			@make -s -C ./mlx42
			$(CC) $(CFLAGS) $(MLX42_FLAGS) -o $(MLX42)
			@echo "minilibx compilation SUCCESS"

$(NAME):	$(OBJ)
			@make -s -C ./libft
			@make -s -C ./MLX42
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42)
			@echo "fractol compilation SUCCESS"

all:		$(NAME) $(MLX42)
clean:
			@make -s clean -C libft
			@make -s clean -C mlx42
			@${RM} $(OBJ)

fclean: 	clean
			@make -s fclean -C libft
			@make -s fclean -C mlx42
			@${RM} $(NAME) ${OBJ}
			@echo "CLEANING SUCCESS"

re:			fclean bonus

.PHONY:		all clean fclean re