/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:24:52 by evallee-          #+#    #+#             */
/*   Updated: 2024/02/19 15:42:41 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**copy_data(t_map map)
{
	char	**copy;
	t_uvec	co;
	char	c;

	co.y = 0;
	copy = malloc(sizeof(char *) * map.dim.y + 1);
	while (co.y < map.dim.y)
	{
		co.x = 0;
		copy[co.y] = malloc(sizeof(char) * (map.dim.x + 1));
		while (co.x < map.dim.x)
		{
			c = map.data[co.y][co.x];
			if (c != '1')
				c = '0';
			copy[co.y][co.x] = c;
			co.x++;
		}
		copy[co.y][co.x] = '\0';
		co.y++;
	}
	copy[co.y] = NULL;
	return (copy);
}

static void	set_fill(t_floodfill *fill, t_uvec check)
{
	t_map	map;
	char	c;

	map = map_get();
	c = map.data[check.y][check.x];
	if (c == 'E')
		fill->found_exit = true;
	if (c == 'C')
		fill->found_coll++;
}

static void	flood(t_floodfill *fill, t_uvec coords, char **copy)
{
	t_map	map;

	map = map_get();
	if (coords.x >= map.dim.x || coords.y >= map.dim.y)
		return ;
	if (copy[coords.y][coords.x] != '0')
		return ;
	copy[coords.y][coords.x] = '1';
	set_fill(fill, coords);
	flood(fill, (t_uvec){coords.x + 1, coords.y}, copy);
	flood(fill, (t_uvec){coords.x - 1, coords.y}, copy);
	flood(fill, (t_uvec){coords.x, coords.y + 1}, copy);
	flood(fill, (t_uvec){coords.x, coords.y - 1}, copy);
}

void	free_copy(char	**copy)
{
	t_uvec	coords;

	coords.y = 0;
	while (copy[coords.y])
		free(copy[coords.y++]);
	free(copy);
}

bool	flood_check(t_map map)
{
	t_floodfill		fill;
	char			**copy;

	fill.found_exit = false;
	fill.found_coll = 0;
	copy = copy_data(map);
	flood(&fill, map.start, copy);
	free_copy(copy);
	return (fill.found_exit && (fill.found_coll == map.num_coll));
}
