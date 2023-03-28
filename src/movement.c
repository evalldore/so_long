/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:55:37 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/28 02:36:30 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	sys_movement(uint32_t ent, va_list args)
{
	t_c_pos		*pos;
	t_c_vel		*vel;
	double		dt;

	dt = va_arg(args, double);
	pos = ecs_comp_get(ent, COMP_POS);
	vel = ecs_comp_get(ent, COMP_VEL);
	if (pos && vel)
	{
		pos->curr.x += vel->curr.x * dt;
		pos->curr.y += vel->curr.y * dt;
	}
}
