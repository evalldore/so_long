/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:54:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/24 02:01:38 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

static int32_t g_anims[MAX_ANIM][4] = {
	{ASSET_SAM_IDLE, ASSET_NONE, ASSET_NONE, ASSET_NONE},
	{ASSET_SAM_WALK1, ASSET_SAM_WALK2, ASSET_SAM_WALK3, ASSET_NONE},
	{ASSET_SAM_WALK2, ASSET_NONE, ASSET_NONE, ASSET_NONE}
};

void	animation_set(ent_id_t ent, int32_t index, int32_t frame)
{
	comp_anim_t		*anim;
	comp_sprite_t	*sprt;

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
	ent_id_t		ent;
	comp_anim_t		*anim;
	comp_sprite_t	*sprt;
	int32_t			nextframe;

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
				nextframe = g_anims[anim->index][anim->frame + 1];
				if (nextframe)
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
