/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:55:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 17:48:41 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav = 480;

static void	gravity(ent_id_t ent, double dt)
{
	comp_grav_t	*grav;
	comp_vel_t	*vel;

	grav = ecs_comp_get(ent, COMP_GRAV);
	vel = ecs_comp_get(ent, COMP_VEL);
	if (grav && vel)
	{
		grav->scale += dt * 3;
		if (grav->scale > 1)
			grav->scale = 1;
		vel->curr.y += (g_grav * dt) * grav->scale;
	}
}

void	sys_movement(double dt)
{
	comp_pos_t	*pos;
	comp_vel_t	*vel;
	ent_id_t	ent;

	ent = 0;
	while (ent < ecs_num())
	{
		pos = ecs_comp_get(ent, COMP_POS);
		vel = ecs_comp_get(ent, COMP_VEL);
		gravity(ent, dt);
		if (pos && vel)
		{
			pos->curr.x += vel->curr.x * dt;
			pos->curr.y += vel->curr.y * dt;
			if (pos->curr.y < 0)
				pos->curr.y = 0;
			if (pos->curr.y > 512)
			{
				pos->curr.y = 512;
				vel->curr.y = 0;
			}
		}
		ent++;
	}
}
