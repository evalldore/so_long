/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:11:13 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 02:36:21 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav = 480;

void	sys_gravity(uint32_t ent, va_list args)
{
	t_c_grav	*grav;
	t_c_vel		*vel;
	double		dt;

	dt = va_arg(args, double);
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
