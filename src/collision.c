/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/29 22:23:20 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "entities.h"
#include "box.h"

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

static bool	resolve(t_uvec coords, t_dvec step, t_dvec pos, t_uvec size)
{
	t_box	s;
	t_box	t;
	double	time;

	s.x = pos.x;
	s.y = pos.y;
	s.w = size.x;
	s.h = size.y;
	t.x = (double)(coords.x * TILE_SIZE);
	t.y = (double)(coords.y * TILE_SIZE);
	t.w = TILE_SIZE;
	t.h = TILE_SIZE;
	time = box_intersect(step, s, t);
	return (true);
}

static bool	check_world(double dt, t_c_pos *pos, t_c_vel *vel, t_c_coll *coll)
{
	t_dvec	coll_pos;
	t_uvec	coords[2];
	t_dvec	step;
	t_uvec	check;

	coll_pos.x = pos->curr.x + coll->offset.x;
	coll_pos.y = pos->curr.y + coll->offset.y;
	step.x = vel->curr.x * dt;
	step.y = vel->curr.y * dt;
	coords[0] = pos_to_coords(coll_pos.x + fmin(step.x, 0.0), coll_pos.y + fmin(step.y, 0.0));
	coords[1] = pos_to_coords(coll_pos.x + coll->size.x + fabs(step.x), coll_pos.y + coll->size.y + fabs(step.y));
	check = coords[0];
	while (check.x <= coords[1].x)
	{
		check.y = coords[0].y;
		while (check.y <= coords[1].y)
		{
			if (check_tile(check, coll_pos, coll->size))
				return (resolve(check, step, coll_pos, coll->size));
			check.y++;
		}
		check.x++;
	}
	return (false);
}

/*static bool	check_world(double dt, t_c_pos *p, t_c_vel *vel, t_c_coll *c)
{
	t_dvec	s;
	t_dvec	cp;
	t_uvec	coords[4];
	t_uvec	check[2];

	s.x = vel->curr.x * dt;
	s.y = vel->curr.y * dt;
	cp.x = p->curr.x + c->offset.x;
	cp.y = p->curr.y + c->offset.y;
	coords[0] = pos_to_coords(cp.x, cp.y);
	coords[1] = pos_to_coords(cp.x + c->size.x, cp.y + c->size.y);
	coords[2] = pos_to_coords(cp.x, cp.y + s.y);
	coords[3] = pos_to_coords(cp.x + c->size.x, cp.y + c->size.y + s.y);
	check[0] = coords[0];
	check[1] = coords[1];
	while (check[0].x != check[1].x)
	{
		if (check[0].x < check[1].x)
			check[0].x++;
	}
	return (false);
}*/

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
