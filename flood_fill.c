/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:48 by hakader           #+#    #+#             */
/*   Updated: 2025/03/12 04:40:44 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	floid_recursive(char **tab, t_axis size, t_axis begin, char target)
// {
// 	if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
// 		return ;
// 	if (tab[begin.y][begin.x] == 'F' || tab[begin.y][begin.x] == '1' || tab[begin.y][begin.x] == 'X' || tab[begin.y][begin.x] == 'E')
// 		return ;
// 	if (tab[begin.y][begin.x] != target && tab[begin.y][begin.x] != 'C'
// 		&& tab[begin.y][begin.x] != 'E' && tab[begin.y][begin.x] != '0')
// 		return ;
// 	tab[begin.y][begin.x] = 'F';
// 	floid_recursive(tab, size, (t_axis){begin.x + 1, begin.y}, target);
// 	floid_recursive(tab, size, (t_axis){begin.x - 1, begin.y}, target);
// 	floid_recursive(tab, size, (t_axis){begin.x, begin.y + 1}, target);
// 	floid_recursive(tab, size, (t_axis){begin.x, begin.y - 1}, target);
// }

// void	flood_fill(t_mlx *mlx)
// {
// 	t_axis	size;
// 	t_axis	begin;
// 	char	target;

// 	size.x = mlx->game.column;
// 	size.y = mlx->game.row;
// 	begin.x = mlx->p_x;
// 	begin.y = mlx->p_y;
// 	target = mlx->game.copy[begin.y][begin.x];
// 	if (target == '1')
// 		return ;
// 	floid_recursive(mlx->game.copy, size, begin, target);
// }

// int	ft_flood_fill_check(t_mlx *mlx)
// {
// 	int		y;
// 	int		x;
// 	t_axis	size;

// 	size.x = mlx->game.column;
// 	size.y = mlx->game.row;
// 	if (!mlx->game.copy)
// 		return (0);
// 	flood_fill(mlx);
// 	y = 0;
// 	print_arr(mlx->game.copy);
// 	while (y < size.y)
// 	{
// 		x = 0;
// 		while (x < size.x)
// 		{
// 			if ((mlx->game.map[y][x] == 'C')
// 				&& mlx->game.copy[y][x] != 'F')
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

void	flood_fill(t_mlx *mlx, int x, int y, char **copy, int exit_allowed)
{
	if (copy[y][x] == '1' || copy[y][x] == 'F' || copy[y][x] == 'X')
		return ;
	if (!exit_allowed)
	{
		if (copy[y][x] == 'E')
			return ;
	}
	copy[y][x] = 'F';
	flood_fill(mlx, x, y + 1, copy, exit_allowed);
	flood_fill(mlx, x, y - 1, copy, exit_allowed);
	flood_fill(mlx, x + 1, y, copy, exit_allowed);
	flood_fill(mlx, x - 1, y, copy, exit_allowed);
}

void	check_flood(t_mlx *mlx, char **map, int exit_allowed)
{
	int i;
	int j;

	i = 0;
	(void)mlx;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				printf("can't reach collectible\n");
				exit(1);
				// close_window(mlx);
			}
			if (exit_allowed)
			{
				if (map[i][j] == 'E')
				{
					printf("can't reach door\n");
					exit(1);
					// close_window(mlx);
				}
			}
			j++;
		}
		i++;
	}
}