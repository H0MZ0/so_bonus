/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:56:02 by hakader           #+#    #+#             */
/*   Updated: 2025/03/12 17:22:47 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_game(t_mlx *mlx)
{
	animate_enemy(mlx);
	rendre_map(mlx);
	return (0);
}

void	exit_door(t_mlx *mlx)
{
	if (mlx->game.c == 0)
		mlx->tx.img = mlx->tx.ldoor;
	else
		mlx->tx.img = mlx->tx.door;
}

void	animate_enemy(t_mlx *mlx)
{
	static int	frame = 0;
	static int	tick = 0;

	tick++;
	if (tick > 700)
	{
		frame = (frame + 1) % 4;
		tick = 0;
	}
	mlx->tx.img = mlx->tx.enemy[frame];
}

void	rendre_helper(t_mlx *mlx, int y, int x)
{
	if (mlx->game.map[y][x] == '1')
		mlx->tx.img = mlx->tx.wall;
	else if (mlx->game.map[y][x] == '0')
		mlx->tx.img = mlx->tx.floor;
	else if (mlx->game.map[y][x] == 'P')
		mlx->tx.img = mlx->tx.player;
	else if (mlx->game.map[y][x] == 'E')
		exit_door(mlx);
	else if (mlx->game.map[y][x] == 'C')
		mlx->tx.img = mlx->tx.coin;
	else if (mlx->game.map[y][x] == 'X')
		animate_enemy(mlx);
}
