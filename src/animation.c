/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:54:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/03/23 20:08:56 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

static int32_t g_anims[MAX_ANIM][4] = {

	{ASSET_SAM_IDLE, ASSET_NONE, ASSET_NONE, ASSET_NONE},
	{ASSET_SAM_WALK1, ASSET_SAM_WALK2, ASSET_SAM_WALK3, ASSET_NONE},
	{ASSET_SAM_WALK2, ASSET_NONE, ASSET_NONE, ASSET_NONE}
};

/*static void	updatesprite(mlx_t	*mlx, comp_sprite_t *sprt, int32_t asset)
{
	delete_instance(mlx);
}*/

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
			nextframe = g_anims[anim->index][anim->frame + 1];
			if (nextframe)
			{
				anim->time += dt;
				if (anim->time > 0.3)
				{
					anim->frame++;
					//updatesprite(mlx, sprt, nextframe);
				}
			}
		}
		ent++;
	}

}
