/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:59:36 by niceguy           #+#    #+#             */
/*   Updated: 2024/02/19 15:42:41 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	map_check_borders(t_map map, t_list *list)
{
	t_uvec	coords;
	char	*content;

	coords.x = 0;
	coords.y = 0;
	while (list)
	{
		content = list->content;
		coords.x = 0;
		while (coords.x < map.dim.x && content[coords.x])
		{
			if (content[coords.x] != '1')
			{
				if (coords.y == 0 || coords.y == (map.dim.y - 1))
					return (false);
				else if (coords.x == 0 || coords.x == (map.dim.x - 1))
					return (false);
			}
			coords.x++;
		}
		list = list->next;
		coords.y++;
	}
	return (true);
}

bool	map_is_valid(t_map map, t_list *list)
{
	if (map.start.x == 0 || map.end.x == 0)
		return (false);
	if (map.num_coll == 0)
		return (false);
	if (!map_check_borders(map, list))
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
