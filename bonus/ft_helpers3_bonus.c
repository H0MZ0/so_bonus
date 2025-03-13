/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:36:11 by hakader           #+#    #+#             */
/*   Updated: 2025/03/13 01:45:47 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char)c;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = src;
		i++;
	}
	return (s);
}
