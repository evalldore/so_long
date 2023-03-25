/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:30:22 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 19:58:50 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	state_set(ent_id_t ent, int32_t next)
{
	comp_state_t	*state;
	comp_anim_t		*anim;
	comp_dir_t		*dir;

	state = ecs_comp_get(ent, COMP_STATE);
	anim = ecs_comp_get(ent, COMP_ANIM);
	dir = ecs_comp_get(ent, COMP_DIRECTION);
	if (state && (state->curr != next))
	{
		state->last = state->curr;
		state->curr = next;
		if (!anim)
			return ;
		if (next == STATE_WALK)
		{
			if (dir->curr)
				animation_set(ent, ANIM_WALK_R, 0);
			else
				animation_set(ent, ANIM_WALK_L, 0);
		}
		if (next == STATE_IDLE)
		{
			if (dir->curr)
				animation_set(ent, ANIM_IDLE_R, 0);
			else
				animation_set(ent, ANIM_IDLE_L, 0);
		}
		if (next == STATE_JUMP)
		{
			if (dir->curr)
				animation_set(ent, ANIM_JUMP_R, 0);
			else
				animation_set(ent, ANIM_JUMP_L, 0);
		}
	}
}

void	sys_state(void)
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
