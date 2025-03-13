/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:15:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/12 17:32:34 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_images(t_mlx *mlx)
{
	int	i;

	if (mlx->tx.wall)
		mlx_destroy_image(mlx->mlx, mlx->tx.wall);
	if (mlx->tx.floor)
		mlx_destroy_image(mlx->mlx, mlx->tx.floor);
	if (mlx->tx.player)
		mlx_destroy_image(mlx->mlx, mlx->tx.player);
	if (mlx->tx.coin)
		mlx_destroy_image(mlx->mlx, mlx->tx.coin);
	if (mlx->tx.door)
		mlx_destroy_image(mlx->mlx, mlx->tx.door);
	if (mlx->tx.ldoor)
		mlx_destroy_image(mlx->mlx, mlx->tx.ldoor);
	i = 0;
	while (i < 4)
	{
		if (mlx->tx.enemy[i])
			mlx_destroy_image(mlx->mlx, mlx->tx.enemy[i]);
		i++;
	}
}

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_images(mlx);
	free_arr(mlx->game.map);
	free_arr(mlx->game.copy);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}
