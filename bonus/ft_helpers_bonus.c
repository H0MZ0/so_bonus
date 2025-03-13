/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:28 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:04:02 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str, int fd)
{
	if (!str)
		return ;
	write (fd, str, ft_strlen(str));
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return ;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	is_valid_ber_file(char *filename)
{
	if (!filename || ft_strlen(filename) <= 4)
		return (0);
	if (filename[0] == '.')
		put_err("Error\nHidder file\n");
	return (ft_strcmp(".ber",
			&filename[ft_strlen(filename) - 4]) == 0);
}

// void	print_arr(char **str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (str[i][j])
// 			printf("%c", str[i][j++]);
// 		i++;
// 	}
// }
