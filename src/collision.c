/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:21:39 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 06:50:05 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "entities.h"

static bool	check_world(comp_pos_t *pos, comp_vel_t *vel, comp_coll_t *coll)
{
	t_map		map;
	vector_t	coll_pos;
	t_coord		coords;

	(void)vel;
	map = map_get();
	coll_pos.x = pos->curr.x + coll->offset.x;
	coll_pos.y = pos->curr.y + coll->offset.y;
	coords = pos_to_coords(coll_pos.x, coll_pos.y);
	//ft_printf("coords x: %d\ncoords y: %d\n", coords.x, coords.y);
	return (map.data[coords.y][coords.x] == '1');	
}

void	sys_collision(double dt)
{
	ent_id_t		ent;
	comp_pos_t		*pos;
	comp_vel_t		*vel;
	comp_coll_t		*coll;
	(void)dt;
	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		vel = ecs_comp_get(ent, COMP_VEL);
		coll = ecs_comp_get(ent, COMP_COLLISION);
		if (!pos || !vel || !coll)
			continue ;
		if (check_world(pos, vel, coll))
		{
			vel->curr.x = 0.0f;
			vel->curr.y = 0.0f;
		}
		ent++;
	}
}
