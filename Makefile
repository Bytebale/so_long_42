NAME = so_long

NAME_BONUS = so_long_bonus

SRC = mandatory/ft_check_map.c\
	mandatory/ft_create_map.c\
	mandatory/ft_moving.c\
	mandatory/ft_read_map.c\
	mandatory/so_long.c\
	gnl/get_next_line_utils.c\
	gnl/get_next_line.c\

SRC_BONUS = gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		bonus/ft_check_map_bonus.c\
		bonus/ft_create_map_bonus.c\
		bonus/ft_enemy.c\
		bonus/ft_graphics_bonus.c\
		bonus/ft_moving_bonus.c\
		bonus/ft_read_map_bonus.c\
		bonus/ft_strj.c\
		bonus/ft_utils_bonus.c\
		bonus/so_long_bonus.c\

HDRS = mandatory/so_long.h

HDRS_BONUS = bonus/so_long_bonus.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		$(CC) $(SRC) $(FLAGS) $(MLX_FLAGS) -o $(NAME)

bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean