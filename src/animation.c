/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:54:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/27 23:11:05 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "entities.h"
#include "assets.h"

static int32_t g_anims[MAX_ANIM][4] = {
	{ASSET_SAM_IDLE_R, ASSET_NONE, ASSET_NONE, ASSET_NONE},
	{ASSET_SAM_WALK_R_1, ASSET_SAM_WALK_R_2, ASSET_SAM_WALK_R_3, ASSET_NONE},
	{ASSET_SAM_WALK_R_3, ASSET_NONE, ASSET_NONE, ASSET_NONE},
	{ASSET_SAM_IDLE_L, ASSET_NONE, ASSET_NONE, ASSET_NONE},
	{ASSET_SAM_WALK_L_1, ASSET_SAM_WALK_L_2, ASSET_SAM_WALK_L_3, ASSET_NONE},
	{ASSET_SAM_WALK_L_3, ASSET_NONE, ASSET_NONE, ASSET_NONE}
};

void	animation_set(uint32_t ent, int32_t index, int32_t frame)
{
	t_c_anim		*anim;
	t_c_sprt	*sprt;

	if (index < 0 || !g_anims[index])
		return ;
	if (!g_anims[index][frame])
		return ;
	anim = ecs_comp_get(ent, COMP_ANIM);
	sprt = ecs_comp_get(ent, COMP_SPRITE);
	if (sprt && anim)
	{
		anim->index = index;
		anim->frame = frame;
		sprt->asset = g_anims[index][frame];
		anim->time = 0.0f;
	}
}

void	sys_animation(double dt)
{
	uint32_t		ent;
	t_c_anim		*anim;
	t_c_sprt	*sprt;

	ent = 0;
	while (ent < ecs_num())
	{
		anim = ecs_comp_get(ent, COMP_ANIM);
		sprt = ecs_comp_get(ent, COMP_SPRITE);
		if (anim && sprt)
		{
			anim->time += dt;
			if (anim->time > 0.1)
			{
				if (g_anims[anim->index][anim->frame + 1])
				{
					animation_set(ent, anim->index, anim->frame + 1);
					continue ;
				}
				animation_set(ent, anim->index, 0);
			}
		}
		ent++;
	}
}
