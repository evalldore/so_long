/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/30 02:02:46 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "entities.h"
#include "box.h"

/*static bool	check_tile(t_uvec coords, t_dvec pos, t_uvec size)
{
	t_uvec	tilesize;
	t_dvec	tilepos;

	if (map_get().data[coords.y][coords.x] != '1')
		return (false);
	tilepos.x = (double)(coords.x * TILE_SIZE);
	tilepos.y = (double)(coords.y * TILE_SIZE);
	tilesize.x = TILE_SIZE;
	tilesize.y = TILE_SIZE;
	return (box_check(pos, size, tilepos, tilesize));
}*/

static double	resolve(t_uvec coords, t_dvec step, t_dvec pos, t_uvec size)
{
	t_box	s;
	t_box	t;

	s.x = pos.x;
	s.y = pos.y;
	s.w = size.x;
	s.h = size.y;
	t.x = (double)(coords.x * TILE_SIZE);
	t.y = (double)(coords.y * TILE_SIZE);
	t.w = TILE_SIZE;
	t.h = TILE_SIZE;
	return (box_intersect_v(step.y, s, t));
}

static bool	check_world(double dt, t_c_pos *pos, t_c_vel *vel, t_c_coll *cc)
{
	t_dvec	cp;
	t_uvec	co[2];
	t_dvec	step;
	t_uvec	check;

	cp.x = pos->curr.x + cc->offset.x;
	cp.y = pos->curr.y + cc->offset.y;
	step.x = vel->curr.x * dt;
	step.y = vel->curr.y * dt;
	co[0] = pos_to_coords(cp.x + fmin(step.x, 0.0), cp.y + fmin(step.y, 0.0));
	co[1] = pos_to_coords(cp.x + cc->size.x + fabs(step.x), cp.y + cc->size.y + fabs(step.y));
	check = co[0];
	while (check.x <= co[1].x)
	{
		check.y = co[0].y;
		while (check.y <= co[1].y)
		{
			if (resolve(check, step, cp, cc->size) < 1.0)
				return (true);
			check.y++;
		}
		check.x++;
	}
	return (false);
}

static bool	check_ents(uint32_t	ent, t_c_pos *pos, t_c_coll *coll)
{
	uint32_t	check_ent;
	t_dvec		coll_pos;
	t_c_coll	*c_coll;
	t_c_pos		*c_pos;
	t_dvec		c_coll_pos;

	coll_pos.x = pos->curr.x + coll->offset.x;
	coll_pos.y = pos->curr.y + coll->offset.y;
	check_ent = 0;
	while (check_ent < ecs_num())
	{
		c_coll = ecs_comp_get(check_ent, COMP_COLLISION);
		c_pos = ecs_comp_get(check_ent, COMP_POS);
		if (ent != check_ent && c_coll && c_pos)
		{
			c_coll_pos.x = c_pos->curr.x + c_coll->offset.x;
			c_coll_pos.y = c_pos->curr.y + c_coll->offset.y;
			if (box_check(coll_pos, coll->size, c_coll_pos, c_coll->size))
				return (true);
		}
		check_ent++;
	}
	return (false);
}

void	sys_collision(uint32_t ent, va_list args)
{
	t_c_pos		*pos;
	t_c_vel		*vel;
	t_c_coll	*coll;
	double		dt;

	dt = va_arg(args, double);
	pos = ecs_comp_get(ent, COMP_POS);
	vel = ecs_comp_get(ent, COMP_VEL);
	coll = ecs_comp_get(ent, COMP_COLLISION);
	if (!pos || !coll)
		return ;
	if (vel && (coll->flags & COLL_FLAG_WORLD))
	{
		if (check_world(dt, pos, vel, coll))
		{
			if (vel->curr.y > 0.0)
				vel->curr.y = 0.0;
		}
	}
	if (check_ents(ent, pos, coll))
		ft_printf("collision with other ent");
}
