NAME		=	fractol


SRC			=	push_swap.c list_utils.c op_one.c op_two.c\
				op_three.c order_functions.c order_two.c order_three.c\
				format_check.c ft_free_arg.c\
				lis_algo.c sorter.c ft_display_error.c ft_lst_mod.c\

MLX42		=	-lmlx -framework OpenGL -framework AppKit
				
LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

$(NAME):	$(OBJ)
			@make -s -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42)
			@echo "fractol compilation SUCCESS"

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -s -C ./libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42)
			@echo "fractol compilation SUCCESS"

$(MLX42):
			@make -s -C ./minilibx
			@echo "minilibx compilation SUCCESS"

clean:
			@make -s clean -C libft
			@${RM} $(OBJ)

fclean: 	clean
			@make -s fclean -C libft
			@${RM} $(NAME) ${BONUS_NAME} ${OBJ} ${BONUS_OBJ}
			@echo "CLEANING SUCCESS"

re:			fclean bonus

.PHONY:		all clean fclean re
