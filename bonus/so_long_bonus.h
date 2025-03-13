/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:40 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:45:41 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define ESC 65307
# define ON_DESTROY 17

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../GNL/get_next_line.h"

typedef struct s_axis
{
	int		x;
	int		y;
}	t_axis;

typedef struct s_map
{
	int		p;
	int		e;
	int		c;
	int		x;
	int		row;
	int		column;
	char	**map;
	char	**copy;
}	t_map;

typedef struct s_image
{
	void	*coin;
	void	*floor;
	void	*player;
	void	*enemy[4];
	void	*door;
	void	*ldoor;
	void	*wall;
	void	*img;
}	t_image;

typedef struct s_mlx
{
	t_map	game;
	t_axis	axis;
	t_image	tx;
	int		lines;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	int		moves;
	int		width;
	int		height;
	int		exit;
}	t_mlx;

/*PARSING*/
void	read_map(t_mlx *mlx, char *map);
void	pars_square(t_mlx *mlx);
void	check_others(t_mlx *mlx);
int		column(char *map);
void	count_things(t_mlx *mlx, int check);
void	copy_map(t_mlx *mlx);
void	find_player(t_mlx *mlx);

void	ft_putnbr(int nbr);
void	print_moves(t_mlx *mlx);
int		is_valid_ber_file(char *filename);
void	print_arr(char **str);
void	free_arr(char **str);
void	check_rl_walls(t_mlx *game);
void	check_fl_walls(t_mlx *game);
void	fl_walls(t_mlx *game, int y);
void	flood_fill(t_mlx *mlx, int x, int y, char **copy);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str, int fd);
void	put_err(char *str);
void	in_mlx(t_mlx *mlx);
void	move_player(t_mlx *mlx, int new_x, int new_y);
size_t	ft_strcpy(char *dst, const char *src);
void	check_flood(t_mlx *mlx, char **map);
void	*ft_memset(void *s, int c, size_t n);

int		ft_flood_fill_check(t_mlx *mlx);
void	print_moves(t_mlx *mlx);
// void	exit_door(t_mlx *mlx);
int		update_game(t_mlx *mlx);
void	exit_door(t_mlx *mlx);
void	animate_enemy(t_mlx *mlx);
void	rendre_map(t_mlx *mlx);
void	count_helper(t_mlx *mlx, int n);
void	rendre_helper(t_mlx *mlx, int y, int x);
void	display_moves(t_mlx *mlx);

// FREE
int		close_window(void *param);
void	free_images(t_mlx *mlx);
void	free_map(char **map, int lines);

#endif
