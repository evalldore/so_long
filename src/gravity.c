/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:11:13 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:21:13 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav = 480;

void	sys_gravity(double dt)
{
	t_c_grav	*grav;
	t_c_vel	*vel;
	uint32_t	ent;

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
