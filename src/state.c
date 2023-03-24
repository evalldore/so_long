/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:30:22 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 03:28:32 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	state_set(ent_id_t ent, int32_t next)
{
	comp_state_t	*state;
	comp_anim_t		*anim;

	state = ecs_comp_get(ent, COMP_STATE);
	anim = ecs_comp_get(ent, COMP_ANIM);
	if (state && (state->curr != next))
	{
		state->last = state->curr;
		state->curr = next;
		if (next == STATE_WALK)
		{
			if (anim)
				animation_set(ent, ANIM_WALK, 0);
		}
		if (next == STATE_IDLE)
		{
			if (anim)
				animation_set(ent, ANIM_IDLE, 0);
		}
		if (next == STATE_JUMP)
		{
			if (anim)
				animation_set(ent, ANIM_JUMP, 0);
		}
	}
}

void	sys_state()
{
	ent_id_t		ent;
	comp_state_t	*state;
	comp_vel_t		*vel;

	ent = 0;
	while (ent < ecs_num())
	{
		state = ecs_comp_get(ent, COMP_STATE);
		vel = ecs_comp_get(ent, COMP_VEL);
		if (state)
		{
			if (vel)
			{
				if (vel->curr.y != 0.0)
					state_set(ent, STATE_JUMP);
				else if (vel->curr.x != 0.0)
					state_set(ent, STATE_WALK);
				else
					state_set(ent, STATE_IDLE);
			}
		}
		ent++;
	}
}
