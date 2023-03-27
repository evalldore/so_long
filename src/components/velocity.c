/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:17:25 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*velocity_new(va_list args)
{
	t_c_vel	*vel;

	vel = malloc(sizeof(t_c_vel));
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

void	comp_vel_reg(void)
{
	ecs_comp_register(COMP_VEL, &velocity_new, &velocity_free);
}
