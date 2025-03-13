/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:21:31 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:35:06 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_filter(char *map)
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	read_map(&mlx, map);
	pars_square(&mlx);
	check_fl_walls(&mlx);
	check_rl_walls(&mlx);
	check_others(&mlx);
	count_things(&mlx, 1);
	copy_map(&mlx);
	find_player(&mlx);
	mlx.exit = 0;
	flood_fill(&mlx, mlx.p_x, mlx.p_y, mlx.game.copy);
	check_flood(&mlx, mlx.game.copy);
	free_arr(mlx.game.copy);
	copy_map(&mlx);
	mlx.exit = 1;
	flood_fill(&mlx, mlx.p_x, mlx.p_y, mlx.game.copy);
	check_flood(&mlx, mlx.game.copy);
	in_mlx(&mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		put_err("Error\n<program> <map>\n");
	if (!is_valid_ber_file(av[1]))
		put_err("Error\nInvalid map name\n");
	map_filter(av[1]);
	return (0);
}
