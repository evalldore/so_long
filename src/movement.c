/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:55:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/22 04:00:37 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav	= 0;

void	sys_movement(double dt)
{
	comp_pos_t	*pos;
	comp_vel_t	*vel;
	comp_grav_t	*grav;	
	ent_id_t	ent;

	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		vel = ecs_comp_get(ent, COMP_VEL);
		grav = ecs_comp_get(ent, COMP_GRAV);
		if (grav)
			vel->curr.y += (g_grav * dt) * grav->scale;
		if (pos && vel)
		{
			pos->curr.x += vel->curr.x * dt;
			pos->curr.y += vel->curr.y * dt;
		}
		ent++;
	}
}