/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/21 02:48:50 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"

void	entities_init()
{
	comp_ctrl_reg();
	comp_pos_reg();
}

ent_id_t	entities_player(unsigned int x, unsigned int y)
{
	ent_id_t	ent;
	comp_pos_t	*pos;
	comp_ctrl_t	*ctrl;

	ent = ecs_create();
	pos = ecs_comp_add(ent, COMP_POS);
	ctrl = ecs_comp_add(ent, COMP_CTRL);
	if (!pos || !ctrl)
		return (-1);
	pos->curr.x = x;
	pos->curr.y = y;
	return (ent);
}

ent_id_t	entities_collectible(unsigned int x, unsigned int y)
{
	ent_id_t	ent;
	comp_pos_t	*pos;

	ent = ecs_create();
	pos = ecs_comp_add(ent, COMP_POS);
	if (!pos)
		return (-1);
	pos->curr.x = x;
	pos->curr.y = y;
	return (ent);
}