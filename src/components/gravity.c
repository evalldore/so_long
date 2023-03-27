/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:51:53 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:17:48 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*gravity_new(va_list args)
{
	t_c_grav	*grav;

	grav = malloc(sizeof(t_c_grav));
	if (!grav)
		return (NULL);
	grav->scale = va_arg(args, double);
	return (grav);
}

void	gravity_free(void	*ptr)
{
	free(ptr);
}

void	comp_grav_reg(void)
{
	ecs_comp_register(COMP_GRAV, &gravity_new, &gravity_free);
}
