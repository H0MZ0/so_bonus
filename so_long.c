/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/12 04:40:54 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fail_flood(t_mlx *mlx)
{
	ft_putstr("why you make me invalid\n", 2);
	free_arr(mlx->game.map);
	free_arr(mlx->game.copy);
	exit(1);
}

void	map_filter(char *map)
{
	t_mlx	mlx;

	mlx.moves = 0;
	read_map(&mlx, map);
	pars_square(&mlx);
	check_fl_walls(&mlx);
	check_rl_walls(&mlx);
	check_others(&mlx);
	count_things(&mlx, 1);
	copy_map(&mlx);
	find_player(&mlx);
	// if (!ft_flood_fill_check(&mlx))
	// 	fail_flood(&mlx);
	flood_fill(&mlx, mlx.p_x, mlx.p_y, mlx.game.copy, 0);
	check_flood(&mlx, mlx.game.copy, 0);
	flood_fill(&mlx, mlx.p_x, mlx.p_y, mlx.game.copy, 1);
	check_flood(&mlx, mlx.game.copy, 1);
	// print_arr(mlx.game.copy);
	in_mlx(&mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error:\n<program> <map>\n");
	if (!is_valid_ber_file(av[1]))
		put_err("Error:\nInvalid map name\n");
	map_filter(av[1]);
	return (0);
}
