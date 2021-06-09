.PHONY	:	all clean fclean re bonus

NAME	=	fractal

MLX_LIB	=	libmlx.dylib

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	additions.c complex.c fractal.c hook.c main.c mlx_adds.c

SRC_B	=	additions.c complex.c fractal.c hook_bonus.c main.c mlx_adds.c

OBJ		=	additions.o complex.o fractal.o hook.o main.o mlx_adds.o

OBJ_B	=	additions.o complex.o fractal.o hook_bonus.o main.o mlx_adds.o

all		:	$(NAME)

$(NAME)	:	$(SRC) fractal.h
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

clean	:
	$(RM) $(OBJ) $(OBJ_B)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

bonus	:	$(SRC_B) fractal.h
	@$(MAKE) SRC="$(SRC_B)" OBJ="$(OBJ_B)"
