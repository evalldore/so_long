/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:51:53 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/24 00:31:23 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	gravity_new(void *ptr, va_list args)
{
	t_c_grav	*grav;

	grav = ptr;
	grav->scale = va_arg(args, double);
}

void	comp_grav_reg(void)
{
	size_t	size;

	size = sizeof(t_c_grav);
	ecs_comp_register(COMP_GRAV, size, &gravity_new, NULL);
}
