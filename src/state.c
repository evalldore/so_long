/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:30:22 by niceguy           #+#    #+#             */
/*   Updated: 2023/05/23 23:05:29 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

static void	dir_anim(uint32_t ent, int32_t l_index, int32_t r_index)
{
	t_c_anim	*anim;
	t_c_dir		*dir;

	anim = ecs_comp_get(ent, COMP_ANIM);
	dir = ecs_comp_get(ent, COMP_DIRECTION);
	if (!anim || !dir)
		return ;
	if (dir->curr)
		animation_set(ent, r_index, 0);
	else
		animation_set(ent, l_index, 0);
}

void	state_set(uint32_t ent, int32_t next)
{
	t_c_state	*state;

	state = ecs_comp_get(ent, COMP_STATE);
	if (state && (state->curr != next))
	{
		state->last = state->curr;
		state->curr = next;
		if (next == STATE_WALK)
			dir_anim(ent, ANIM_WALK_L, ANIM_WALK_R);
		if (next == STATE_IDLE)
			dir_anim(ent, ANIM_IDLE_L, ANIM_IDLE_R);
	}
}

void	sys_state(uint32_t ent, va_list args)
{
	t_c_state	*state;
	t_c_vel		*vel;
	t_c_ctrl	*ctrl;

	(void)args;
	state = ecs_comp_get(ent, COMP_STATE);
	vel = ecs_comp_get(ent, COMP_VEL);
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	if (!state || !vel)
		return ;
	if (vel->curr.y != 0.0 || ctrl->jump)
	{
		dir_anim(ent, ANIM_JUMP_L, ANIM_JUMP_R);
		state_set(ent, STATE_JUMP);
	}
	else if (vel->curr.x != 0.0)
		state_set(ent, STATE_WALK);
	else
		state_set(ent, STATE_IDLE);
}
