/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:11:13 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 19:13:04 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav = 480;

void	sys_gravity(double dt)
{
	comp_grav_t	*grav;
	comp_vel_t	*vel;
	ent_id_t	ent;

	ent = 0;
	while (ent < ecs_num())
	{
		grav = ecs_comp_get(ent, COMP_GRAV);
		vel = ecs_comp_get(ent, COMP_VEL);
		if (grav && vel)
		{
			grav->scale += dt * 3;
			if (grav->scale > 1)
				grav->scale = 1;
			vel->curr.y += (g_grav * dt) * grav->scale;
		}
		ent++;
	}
}
