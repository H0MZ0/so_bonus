/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:54:35 by hakader           #+#    #+#             */
/*   Updated: 2025/03/08 01:37:28 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fl_walls(t_mlx *mlx, int y)
{
	int	x;

	x = 0;
	if (!mlx->game.map[y])
		return ;
	while (mlx->game.map[y][x] && mlx->game.map[y][x] != '\n')
	{
		if (mlx->game.map[y][x] != '1')
		{
			free_arr(mlx->game.map);
			put_err("Error:\nCheck your walls\n");
		}
		x++;
	}
	mlx->game.column = x;
}

void	check_fl_walls(t_mlx *mlx)
{
	int	y;

	y = 0;
	fl_walls(mlx, 0);
	while (mlx->game.map[y + 1])
		y++;
	fl_walls (mlx, y);
}

void	check_rl_walls(t_mlx *mlx)
{
	int (y), (x);
	y = 0;
	while (mlx->game.map[y])
	{
		x = 0;
		while (mlx->game.map[y][x])
			x++;
		if (mlx->game.map[y][0] != '1' || mlx->game.map[y][x - 2] != '1')
		{
			free_arr(mlx->game.map);
			put_err("Error:\nCheck your walls\n");
		}
		y++;
	}
	mlx->game.row = y;
}
