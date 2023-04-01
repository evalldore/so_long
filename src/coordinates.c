/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:32:47 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 22:55:59 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates.h"

t_uvec	pos_to_coords(double x, double y)
{
	t_uvec	coord;

	coord.x = (uint32_t)(x / TILE_SIZE);
	coord.y = (uint32_t)(y / TILE_SIZE);
	return (coord);
}

static void set_line_vars(t_uvec start, t_uvec end, t_ivec *d, t_ivec *s)
{
	d->x = abs((int32_t)(end.x - start.x));
	d->y = abs((int32_t)(end.y - start.y));
	s->x = 1;
	s->y = 1;
	if (start.x > end.x)
		s->x = -1;
	if (start.y > end.y)
		s->y = -1;
}

void line_coords(t_uvec start, t_uvec end, void (*f)(uint32_t, uint32_t)) 
{
	t_ivec		d;
	t_ivec		s;
	int32_t		err;

	if (!f)
		return ;
	set_line_vars(start, end, &d, &s);
	err = d.x - d.y;
	while (start.x != end.x || start.y != end.y)
	{
		f(start.x, start.y);
		if ((2 * err) > -d.y) 
		{
			err -= d.y; 
			start.x += s.x; 
		}
		if ((2 * err) < d.x) 
		{
			err += d.x;
			start.y += s.y;
		}
	}
}
