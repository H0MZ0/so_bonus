/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:29 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:45:15 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = ft_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, len + 1);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (--len >= 0)
	{
		if (str[len] == '-')
			break ;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	draw_rectangle(t_mlx *mlx, int x, int y)
{
	int (i), (j);
	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
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
		return ;
	mlx->height = 30;
	mlx->width = 130;
	draw_rectangle(mlx, 25, 25);
	mlx_string_put(mlx->mlx, mlx->win, 35, 45, 0xFFFFFF, "M O V E S :");
	mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0xFAFA, str);
	free(str);
}
