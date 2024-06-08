NAME		=	fractol

SRC			=	src/*.c

MLX42_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
                
LIBFT		=	libft/libft.a

MLX42		=	MLX42/libmlx42.a

CC			=	clang

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

OBJ			=	$(SRC:.c=.o)

%.o: %.c
            $(CC) $(CFLAGS) -c $< -o $@ -Iincludes

$(MLX42):
            @make -s -C ./mlx42
            @echo "mlx42 compilation SUCCESS"

$(NAME):	$(OBJ) $(MLX42)
            @make -s -C ./libft
            @$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42)
            @echo "fractol compilation SUCCESS"

all:		$(NAME)

clean:
            @make -s clean -C libft
            @make -s clean -C mlx42
            @${RM} $(OBJ)

fclean: 	clean
            @make -s fclean -C libft
            @make -s fclean -C mlx42
            @${RM} $(NAME) ${OBJ}
            @echo "CLEANING SUCCESS"

re:			fclean all

.PHONY:		all clean fclean re