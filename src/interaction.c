/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:37:07 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/31 05:55:44 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

void	collect(uint32_t ent)
{
	ecs_remove(ent);
}

void	kill(uint32_t ent)
{
	t_c_pos		*pos;

	pos = ecs_comp_get(ent, COMP_POS);
	entities_collectible(pos->curr.x, pos->curr.y);
	ecs_remove(ent);
}

void	interact(uint32_t ent1, uint32_t ent2)
{
	t_c_coll	*entcomp1;
	t_c_coll	*entcomp2;

	entcomp1 = ecs_comp_get(ent1, COMP_COLLISION);
	entcomp2 = ecs_comp_get(ent2, COMP_COLLISION);
	if ((entcomp1->flags & FLAG_PLAYER) && (entcomp2->flags & FLAG_COLLECTIBLE))
		collect(ent2);
	if ((entcomp1->flags & FLAG_PROJECTILE) && (entcomp2->flags & FLAG_ENEMIES))
		kill(ent2);
}
