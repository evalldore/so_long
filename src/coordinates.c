/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:32:47 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/30 17:22:45 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"

t_uvec	pos_to_coords(double x, double y)
{
	t_uvec	coord;

	coord.x = (uint32_t)(x / TILE_SIZE);
	coord.y = (uint32_t)(y / TILE_SIZE);
	return (coord);
}
