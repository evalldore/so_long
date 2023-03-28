/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 18:08:38 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"
#include <stdlib.h>

static bool	check_tile(t_uvec coords, t_dvec pos, t_uvec size)
{
	t_map	map;
	t_uvec	tilesize;
	t_dvec	tilepos;

	map = map_get();
	if (map.data[coords.y][coords.x] != '1')
		return (false);
	tilepos.x = (double)(coords.x * TILE_SIZE);
	tilepos.y = (double)(coords.y * TILE_SIZE);
	tilesize.x = TILE_SIZE;
	tilesize.y = TILE_SIZE;
	return (box_check(pos, size, tilepos, tilesize));
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
	if (vel)
	{
		if ((coll->flags & COLL_FLAG_WORLD) && check_world(dt, pos, vel, coll))
		{
			if (vel->curr.y > 0.0)
				vel->curr.y = 0.0;
		}
	}
	if (check_ents(ent, pos, coll))
		ft_printf("collision with other ent");
}
