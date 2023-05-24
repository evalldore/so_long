/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:44:34 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	velocity_new(void *ptr, va_list args)
{
	t_c_vel	*vel;

	vel = ptr;
	vel->curr.x = va_arg(args, double);
	vel->curr.y = va_arg(args, double);
	vel->last.x = vel->curr.x;
	vel->last.y = vel->curr.y;
}

void	comp_vel_reg(void)
{
	size_t	size;

	size = sizeof(t_c_vel);
	ecs_comp_register(COMP_VEL, size, &velocity_new, NULL);
}
