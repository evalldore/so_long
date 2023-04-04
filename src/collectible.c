/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:36:13 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:37:06 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entities.h"
#include <math.h>

static void	move_to_player(t_dvec pos, t_c_vel *vel)
{
	t_c_pos		*player_pos;

	player_pos = ecs_comp_get(game_get().player, COMP_POS);
	if (!player_pos)
		return ;
	vel->curr.x = (player_pos->curr.x - pos.x) * 3.0;
	vel->curr.y = ((player_pos->curr.y - 24) - pos.y) * 3.0;
}

void	sys_collectible(uint32_t ent, va_list args)
{
	t_c_collect	*collect;
	t_c_vel		*vel;
	t_c_pos		*pos;

	(void)args;
	collect = ecs_comp_get(ent, COMP_COLLECTIBLE);
	vel = ecs_comp_get(ent, COMP_VEL);
	pos = ecs_comp_get(ent, COMP_POS);
	if (!collect || !vel || !pos)
		return ;
	move_to_player(pos->curr, vel);
}
