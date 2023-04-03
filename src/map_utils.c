/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:59:36 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 19:20:50 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_is_valid(t_map map)
{
	if (map.dim_x <= map.dim_y)
		return (false);
	if (map.start.x == 0 || map.end.x == 0)
		return (false);
	if (map.num_coll == 0)
		return (false);
	return (true);
}

size_t	row_len(char	*line)
{
	size_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len);
}

bool	map_check_borders(t_map map)
{
	t_uvec	coords;

	coords.x = 0;
	coords.y = 0;
	while (coords.x < (map.dim_x))
	{
		if (map.data[0][coords.x] != '1')
			return (false);
		if (map.data[map.dim_y - 1][coords.x] != '1')
			return (false);
		coords.x++;
	}
	while (coords.y < map.dim_y)
	{
		if (map.data[coords.y][0] != '1')
			return (false);
		if (map.data[coords.y][map.dim_x - 1] != '1')
			return (false);
		coords.y++;
	}
	return (true);
}

void	map_iter_tiles(t_map map, t_tileiterator it, ...)
{
	va_list	args_orig;
	va_list	args_tile;
	t_uvec	co;

	if (!it)
		return ;
	co.y = 0;
	va_start(args_orig, it);
	while (map.data[co.y])
	{
		co.x = 0;
		while (map.data[co.y][co.x])
		{
			va_copy(args_tile, args_orig);
			it(co.x, co.y, map.data[co.y][co.x], args_tile);
			co.x++;
		}
		co.y++;
	}
	va_end(args_orig);
	va_end(args_tile);
}
