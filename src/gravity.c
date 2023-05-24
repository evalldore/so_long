/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:11:13 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/23 23:01:49 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

static float	g_grav = 480;

void	sys_gravity(uint32_t ent, va_list args)
{
	t_c_grav	*grav;
	t_c_vel		*vel;
	mlx_t		*mlx;

	mlx = va_arg(args, void *);
	grav = ecs_comp_get(ent, COMP_GRAV);
	vel = ecs_comp_get(ent, COMP_VEL);
	if (!grav || !vel)
		return ;
	grav->scale += mlx->delta_time * 3;
	if (grav->scale > 1)
		grav->scale = 1;
	vel->curr.y += (g_grav * mlx->delta_time) * grav->scale;
}
