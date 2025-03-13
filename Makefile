CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm

SRC_MANDATORY = so_long.c map_parsing.c map_parsing2.c \
                 ft_helpers.c ft_helpers2.c check_walls.c \
                 init_window.c player.c ft_free.c flood_fill.c

SRC_BONUS = bonus/so_long_bonus.c bonus/map_parsing_bonus.c bonus/map_parsing2_bonus.c \
            bonus/ft_helpers_bonus.c bonus/ft_helpers2_bonus.c bonus/check_walls_bonus.c \
            bonus/init_window_bonus.c bonus/player_bonus.c bonus/ft_free_bonus.c \
            bonus/flood_fill_bonus.c bonus/init_helper_bonus.c bonus/init_helper2_bonus.c \
            bonus/ft_helpers3_bonus.c

GNL_FILES = GNL/get_next_line.c GNL/get_next_line_utils.c

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o) $(GNL_FILES:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o) $(GNL_FILES:.c=.o)

NAME_MANDATORY = so_long
NAME_BONUS = so_long_bonus

all: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

$(NAME_MANDATORY): $(OBJ_MANDATORY)
	@$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX) -o $(NAME_MANDATORY)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) -o $(NAME_BONUS)

clean:
	@rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
