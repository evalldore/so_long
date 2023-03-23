/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 01:36:22 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*velocity_new(va_list args)
{
	comp_vel_t	*vel;

	vel = malloc(sizeof(comp_vel_t));
	if (!vel)
		return (NULL);
	vel->curr.x = va_arg(args, double);
	vel->curr.y = va_arg(args, double);
	vel->last.x = vel->curr.x;
	vel->last.y = vel->curr.y;
	return (vel);
}

void	velocity_free(void	*ptr)
{
	free(ptr);
}

void	comp_vel_reg()
{
	ecs_comp_register(COMP_VEL, &velocity_new, &velocity_free);
}
