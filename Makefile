NAME	=   cube3D

MLX_PATH = includes/minilibx_opengl_20191021/
MLX_NAME = libmlx.a

SRCS	=	srcs/main.c \
			srcs/parsing/pars_hub.c \
			srcs/parsing/pars_utils.c \
			srcs/parsing/ft_split_cb3d.c \
			srcs/parsing/pars_hub2.c \
			srcs/parsing/pars_hub3.c \
			srcs/parsing/ft_memchr_cb.c \
			srcs/parsing/ft_memcpy_cb.c \
			srcs/parsing/ft_strtrim_cb.c \
			srcs/parsing/pars_map_check.c \
			srcs/parsing/pars_map_check2.c \
			srcs/parsing/ft_strdup_cb.c \
			srcs/parsing/pars_blob.c \

SRCS_B =	srcs/main.c \
			srcs/parsing/pars_hub.c \
			srcs/parsing/pars_utils.c \
			srcs/parsing/ft_split_cb3d.c \
			srcs/parsing/pars_hub2.c \
			srcs/parsing/pars_hub3.c \
			srcs/parsing/ft_memchr_cb.c \
			srcs/parsing/ft_memcpy_cb.c \
			srcs/parsing/ft_strtrim_cb.c \
			srcs/parsing/pars_map_check.c \
			srcs/parsing/pars_map_check2.c \
			srcs/parsing/ft_strdup_cb.c \
			srcs/parsing/pars_blob.c \

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM	=		rm -f
CC	= gcc
FLAGS	= -Wall -Wextra -Werror

.c.o	:
	${CC} ${FLAGS} -c $< -o $@

$(NAME)	: $(OBJS)
	${CC} $(OBJS) -o $(NAME)

all	: $(NAME)

bonus : fclean $(OBJS_B)
	$(CC) $(OBJS_B) -o $(NAME)

fclean	: clean
	$(RM) $(NAME)
	clear

clean	:
	$(RM) -f $(OBJS)
	$(RM) -f $(OBJS_B)

re	: fclean all

norm :
	norminette -R CheckForbidenHeader

.PHONY	: all fclean re .c.o clean norm
