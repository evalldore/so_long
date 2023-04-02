/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/01 23:21:30 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "box.h"
#include "map.h"
#include "interact.h"
#include "coordinates.h"

static bool	check_tile(t_uvec coords, t_dvec pos, t_uvec size)
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
}

static void	check_world(double dt, t_c_pos *pos, t_c_vel *vel, t_c_coll *cc)
{
	t_dvec			cp;
	t_uvec			test;
	t_dvec			tp;

	cp.x = pos->curr.x + cc->offset.x;
	cp.y = pos->curr.y + cc->offset.y;
	tp.x = cp.x;
	tp.y = pos->curr.y;
	if (vel->curr.y < 0.0)
		tp.y = cp.y;
	if (vel->curr.x > 0.0)
		tp.x = cp.x + cc->size.x;
	test = pos_to_coords(pos->curr.x, tp.y + vel->curr.y * dt);
	if (check_tile(test, cp, cc->size))
	{
		if (vel->curr.y > 0.0)
			pos->curr.y = (test.y * TILE_SIZE);
		vel->curr.y = 0.0;
	}
	test = pos_to_coords(tp.x + vel->curr.x * dt, pos->curr.y - 1);
	if (check_tile(test, cp, cc->size))
		vel->curr.x = 0.0;
}

static void	check_ents(uint32_t	ent, t_c_pos *pos, t_c_coll *coll)
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
				interact(ent, check_ent);
		}
		check_ent++;
	}
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
	if (vel && (coll->flags & FLAG_WORLD))
		check_world(dt, pos, vel, coll);
	check_ents(ent, pos, coll);
}
