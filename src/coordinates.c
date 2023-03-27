/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:32:47 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:26:25 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"

t_uvec	pos_to_coords(double x, double y)
{
	t_uvec	coord;

	coord.x = (uint32_t)round((x + (TILE_SIZE / 2)) / TILE_SIZE) - 1;
	coord.y = (uint32_t)round((y + (TILE_SIZE / 2)) / TILE_SIZE);
	return (coord);
}

void	ent_coords(t_uvec *coords[2], t_c_pos pos, t_c_coll *coll, t_c_vel *vel)
{
	(void)coords;
	(void)pos;
	(void)coll;;
	(void)vel;
}