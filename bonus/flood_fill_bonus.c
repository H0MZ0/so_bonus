/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:30:48 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:08:38 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_mlx *mlx, int x, int y, char **copy)
{
	if (copy[y][x] == '1' || copy[y][x] == 'F' || copy[y][x] == 'X')
		return ;
	if (!mlx->exit)
	{
		if (copy[y][x] == 'E')
			return ;
	}
	copy[y][x] = 'F';
	flood_fill(mlx, x, y + 1, copy);
	flood_fill(mlx, x, y - 1, copy);
	flood_fill(mlx, x + 1, y, copy);
	flood_fill(mlx, x - 1, y, copy);
}

void	flood_err(t_mlx *mlx, char *str)
{
	ft_putstr(str, 2);
	free_arr(mlx->game.map);
	free_arr(mlx->game.copy);
	exit(1);
}

void	check_flood(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				flood_err(mlx, "Error\ncan't reach collectible\n");
			if (mlx->exit)
			{
				if (map[i][j] == 'E')
					flood_err(mlx, "Error\ncan't reach door\n");
			}
			j++;
		}
		i++;
	}
}
