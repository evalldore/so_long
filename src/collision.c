/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 03:30:48 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include <stdlib.h>

bool	is_colliding(t_dvector pos, t_uvector size, t_dvector tpos, t_uvector tsize)
{
	if (tpos.x <= (pos.x + size.x) && (tpos.x + tsize.x) >= pos.x)
	{
		if (tpos.y <= (pos.y + size.y) && (tpos.y + tsize.y) >= pos.y)
			return (true);
	}
	return (false);
}

static bool check_tile(t_uvector coords, t_dvector pos, t_uvector size)
{
	t_uvector	tilesize;
	t_dvector	tilepos;

	tilepos.x = (double)(coords.x * TILE_SIZE);
	tilepos.y = (double)(coords.y * TILE_SIZE);
	tilesize.x = (double)TILE_SIZE;
	tilesize.y = (double)TILE_SIZE;
	return (is_colliding(pos, size, tilepos, tilesize));
}

static bool	check_world(double dt, comp_pos_t *pos, comp_vel_t *vel, comp_coll_t *coll)
{
	t_map		map;
	t_dvector	coll_pos;
	t_uvector	coords[2];
	t_dvector	step;
	t_uvector	check;

	map = map_get();
	coll_pos.x = pos->curr.x + coll->offset.x;
	coll_pos.y = pos->curr.y + coll->offset.y;
	step.x = vel->curr.x * dt;
	step.y = vel->curr.y * dt;
	coords[0] = pos_to_coords(coll_pos.x + fmin(step.x, 0.0), coll_pos.y + fmin(step.y, 0.0));
	coords[1] = pos_to_coords(coll_pos.x + coll->size.x + fabs(step.x), coll_pos.y + coll->size.y + fabs(step.y));
	check.x = coords[0].x;
	while (check.x <= coords[1].x)
	{
		check.y = coords[0].y;
		while (check.y <= coords[1].y)
		{
			if ((map.data[check.y][check.x] == '1') && check_tile(check, coll_pos, coll->size))
				return (true);
			check.y++;
		}
		check.x++;
	}
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
			if (vel->curr.y > 0.0)
				vel->curr.y = 0.0;
		}
		ent++;
	}
}
