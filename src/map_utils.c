/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:59:36 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 20:17:45 by niceguy          ###   ########.fr       */
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

bool map_check_borders(t_map map)
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