/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 02:37:15 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include <stdlib.h>

static bool	check_world(double dt, comp_pos_t *pos, comp_vel_t *vel, comp_coll_t *coll)
{
	t_map		map;
	t_dvector	coll_pos;
	t_uvector	coords[2];
	t_dvector	step;

	map = map_get();
	coll_pos.x = pos->curr.x + coll->offset.x;
	coll_pos.y = pos->curr.y + coll->offset.y;
	step.x = vel->curr.x * dt;
	step.y = vel->curr.y * dt;
	coords[0] = pos_to_coords(coll_pos.x + fmin(step.x, 0.0), coll_pos.y + fmin(step.y, 0.0));
	coords[1] = pos_to_coords(coll_pos.x + coll->size.x + fabs(step.x), coll_pos.y + coll->size.y + fabs(step.y));
	while (coords[0].x <= coords[1].x)
	{
		while (coords[0].y <= coords[1].y)
		{
			if (map.data[coords[0].y][coords[0].x] == '1')
				return (true);
			coords[0].y++;
		}
		coords[0].x++;
	}
	//ft_printf("coords x: %d\ncoords y: %d\n", coords.x, coords.y);
	return (false);
}

void	sys_collision(double dt)
{
	ent_id_t		ent;
	comp_pos_t		*pos;
	comp_vel_t		*vel;
	comp_coll_t		*coll;

	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		vel = ecs_comp_get(ent, COMP_VEL);
		coll = ecs_comp_get(ent, COMP_COLLISION);
		if (!pos || !vel || !coll)
			continue ;
		if ((coll->flags & COLL_FLAG_WORLD) && check_world(dt, pos, vel, coll))
		{
			if (vel->curr.y < 0.0)
				vel->curr.y = 0.0;
		}
		ent++;
	}
}
