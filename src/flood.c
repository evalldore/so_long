/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:24:52 by evallee-          #+#    #+#             */
/*   Updated: 2023/04/06 06:48:44 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**copy_data(t_map map)
{
	char	**copy;
	t_uvec	co;
	char	c;

	co.y = 0;
	copy = malloc(sizeof(char *) * map.dim_y + 1);
	while (co.y < map.dim_y)
	{
		co.x = 0;
		copy[co.y] = malloc(sizeof(char) * (map.dim_x + 1));
		while (co.x < map.dim_x)
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

static void	flood(t_floodfill *fill, t_uvec coords, char tiles[2], char **copy)
{
	t_uvec	check;
	t_map	map;

	map = map_get();
	if (coords.x < 0 || coords.x >= map.dim_x)
		return ;
	if (coords.y < 0 || coords.y >= map.dim_y)
		return ;
	if (copy[coords.y][coords.x] != tiles[0])
		return ;
	copy[coords.y][coords.x] = tiles[1];
	set_fill(fill, coords);
	check.x = coords.x + 1;
	check.y = coords.y;
	flood(fill, check, tiles, copy);
	check.x = coords.x - 1;
	check.y = coords.y;
	flood(fill, check, tiles, copy);
	check.x = coords.x;
	check.y = coords.y + 1;
	flood(fill, check, tiles, copy);
	check.x = coords.x;
	check.y = coords.y - 1;
	flood(fill, check, tiles, copy);
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
	char			tiles[2];
	char			**copy;

	tiles[0] = '0';
	tiles[1] = '1';
	fill.found_exit = false;
	fill.found_coll = 0;
	copy = copy_data(map);
	flood(&fill, map.start, tiles, copy);
	free_copy(copy);
	return (fill.found_exit && (fill.found_coll == map.num_coll));
}
