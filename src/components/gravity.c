/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:51:53 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 15:40:21 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*gravity_new(va_list args)
{
	comp_grav_t	*grav;

	grav = malloc(sizeof(comp_grav_t));
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
