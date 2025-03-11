/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:56:02 by hakader           #+#    #+#             */
/*   Updated: 2025/03/11 17:15:08 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_game(t_mlx *mlx)
{
	animate_enemy(mlx);
	rendre_map(mlx);
	// usleep(1000);
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
	static	int	frame = 0;
	static	int	tick = 0;

	tick++;
	if (tick > 300)
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

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len = ft_len(n);
	char	*str;
	long	nb = n;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len-- > 0)
	{
		if (str[len] == '-')
			break;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	draw_rectangle(t_mlx *mlx, int x, int y, int width, int height)
{
	int	i, j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x + j, y + i, 0x000000);
			j++;
		}
		i++;
	}
}

void	display_moves(t_mlx *mlx)
{
	char	*str;

	str = ft_itoa(mlx->moves);
	if (!str)
		return;
	draw_rectangle(mlx, 25, 25, 130, 30);
	mlx_string_put(mlx->mlx, mlx->win, 35, 45, 0xFFFFFF, "M O V E S :");
	mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0xFAFA, str);
	free(str);
}


