/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:32:47 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/03 15:07:46 by evallee-         ###   ########.fr       */
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

static int32_t	set_line_vars(t_uvec start, t_uvec end, t_ivec *d, t_ivec *s)
{
	d->x = abs((int32_t)(end.x - start.x));
	d->y = abs((int32_t)(end.y - start.y));
	s->x = -1;
	s->y = -1;
	if (start.x < end.x)
		s->x = 1;
	if (start.y < end.y)
		s->y = 1;
	return (d->x - d->y);
}

bool	line_coords(t_uvec start, t_uvec end, bool (*f)(uint32_t, uint32_t))
{
	t_ivec		d;
	t_ivec		s;
	int32_t		err;

	if (!f)
		return (false);
	err = set_line_vars(start, end, &d, &s);
	while (1)
	{
		if (!f(start.x, start.y))
			return (false);
		if (start.x == end.x && start.y == end.y)
			break ;
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
	return (true);
}
