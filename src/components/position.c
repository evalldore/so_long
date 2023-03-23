/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:16:41 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 01:36:14 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	*position_new(va_list args)
{
	comp_pos_t	*pos;

	pos = malloc(sizeof(comp_pos_t));
	if (!pos)
		return (NULL);
	pos->curr.x = va_arg(args, double);
	pos->curr.y = va_arg(args, double);
	pos->last.x = pos->curr.x;
	pos->last.y = pos->curr.y;
	return (pos);
}

void	position_free(void	*ptr)
{
	free(ptr);
}

void	comp_pos_reg()
{
	ecs_comp_register(COMP_POS, &position_new, &position_free);
}
