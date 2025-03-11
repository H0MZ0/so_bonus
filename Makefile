CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm

SRC = so_long.c map_parsing.c map_parsing2.c GNL/get_next_line.c GNL/get_next_line_utils.c\
		ft_helpers.c ft_helpers2.c check_walls.c init_window.c player.c ft_free.c\
		flood_fill.c init_helper.c
OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) mlx/libmlx.a
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

mlx/libmlx.a:
	@$(MAKE) -C mlx

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C mlx clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C mlx clean

re: fclean all

.PHONY: all clean fclean re
