/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:01:07 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:04:04 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_map(t_mlx *mlx, char *map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		put_err("Failed to open map\n");
	mlx->lines = column(map);
	mlx->game.map = malloc((mlx->lines + 1) * sizeof(char *));
	if (!mlx->game.map)
	{
		close(fd);
		return ;
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		mlx->game.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	mlx->game.map[i] = NULL;
	close(fd);
}

void	pars_square(t_mlx *mlx)
{
	int	check;

	check = 0;
	mlx->axis.y = 0;
	if (!mlx->game.map)
		return ;
	while (mlx->game.map[0][check] && mlx->game.map[0][check] != '\n')
		check++;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x]
			&& mlx->game.map[mlx->axis.y][mlx->axis.x] != '\n')
			mlx->axis.x++;
		if (check != mlx->axis.x)
		{
			free_arr(mlx->game.map);
			put_err("Error\nInvalid map : {{ NOT square }}\n");
		}
		mlx->axis.y++;
	}
}

void	check_others(t_mlx *mlx)
{
	mlx->axis.y = 0;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x])
		{
			if (!(mlx->game.map[mlx->axis.y][mlx->axis.x] == 'C'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == 'E'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == 'P'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == 'X'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '0'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '1'
				|| mlx->game.map[mlx->axis.y][mlx->axis.x] == '\n'))
			{
				free_arr(mlx->game.map);
				put_err("Error\nInvalid character in map\n");
			}
			mlx->axis.x++;
		}
		mlx->axis.y++;
	}
}

int	column(char *map)
{
	char	*str;
	int		fd;
	int		size;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		put_err("Failed to open map\n");
	size = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		size++;
		str = get_next_line(fd);
	}
	close(fd);
	return (size);
}

void	count_things(t_mlx *mlx, int check)
{
	mlx->game.p = 0;
	mlx->game.x = 0;
	mlx->game.e = 0;
	mlx->game.c = 0;
	mlx->axis.y = 0;
	while (mlx->game.map[mlx->axis.y])
	{
		mlx->axis.x = 0;
		while (mlx->game.map[mlx->axis.y][mlx->axis.x])
		{
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'P')
				mlx->game.p++;
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'X')
				mlx->game.x++;
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'E')
				mlx->game.e++;
			if (mlx->game.map[mlx->axis.y][mlx->axis.x] == 'C')
				mlx->game.c++;
			mlx->axis.x++;
		}
		mlx->axis.y++;
	}
	count_helper(mlx, check);
}
