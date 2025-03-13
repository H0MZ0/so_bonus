/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:40:33 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:39:08 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	put_err(char *str)
{
	ft_putstr(str, 2);
	exit (1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + 48);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

// void	print_moves(t_mlx *mlx)
// {
// 	mlx->moves += 1;
// 	ft_putstr("moves: ", 1);
// 	ft_putnbr(mlx->moves);
// 	ft_putstr("\n", 1);
// }
