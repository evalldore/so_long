/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:28:58 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/26 06:18:05 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*collision_new(va_list args)
{
	comp_coll_t	*coll;

	coll = malloc(sizeof(comp_coll_t));
	if (!coll)
		return (NULL);
	coll->width = va_arg(args, unsigned int);
	coll->height = va_arg(args, unsigned int);
	coll->offset.x = va_arg(args, double);
	coll->offset.y = va_arg(args, double);
	return (coll);
}

void	collision_free(void	*ptr)
{
	free(ptr);
}

void	comp_coll_reg(void)
{
	ecs_comp_register(COMP_COLLISION, &collision_new, &collision_free);
}
