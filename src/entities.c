/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 19:02:24 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"
#include "libft.h"

void	entities_init(void)
{
	comp_ctrl_reg();
	comp_pos_reg();
	comp_vel_reg();
	comp_grav_reg();
	comp_sprite_reg();
	comp_coll_reg();
	comp_anim_reg();
	comp_state_reg();
	comp_dir_reg();
	comp_project_reg();
	comp_ai_reg();
	comp_collect_reg();
}

uint32_t	entities_player(double x, double y)
{
	uint32_t		ent;
	uint32_t		collflags;

	collflags = (FLAG_WORLD | FLAG_PLAYER);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_CTRL, 0);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_GRAV, 1, 1.0);
	ecs_comp_add(ent, COMP_SPRITE, 3, ASSET_SAM_IDLE_R, -20.0, -40.0);
	ecs_comp_add(ent, COMP_COLLISION, 5, 16, 32, -8.0, -32.0, collflags);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_IDLE_R);
	ecs_comp_add(ent, COMP_STATE, 1, STATE_IDLE);
	ecs_comp_add(ent, COMP_DIRECTION, 1, true);
	return (ent);
}

uint32_t	entities_collectible(double x, double y)
{
	uint32_t		ent;
	uint32_t		collflags;

	collflags = (FLAG_COLLECTIBLE);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_SPRITE, 3, ASSET_ENERGY_1, -4.0, -4.0);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_ENERGY);
	ecs_comp_add(ent, COMP_COLLECTIBLE, 1, COLLECT_HP);
	ecs_comp_add(ent, COMP_COLLISION, 5, 8, 8, -4.0, -4.0, collflags);
	return (ent);
}

uint32_t	entities_projectile(double x, double y, bool isRight)
{
	uint32_t		ent;
	uint32_t		collflags;
	double			vel;
	int32_t			asset;
	int32_t			anim;

	vel = -BULLET_SPEED;
	asset = ASSET_PROJECT_L_1;
	anim = ANIM_PROJECT_L;
	if (isRight)
	{
		vel = BULLET_SPEED;
		asset = ASSET_PROJECT_R_1;
		anim = ANIM_PROJECT_R;
	}
	collflags = (FLAG_PROJECTILE);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_VEL, 2, vel, 0.0);
	ecs_comp_add(ent, COMP_SPRITE, 3, asset, -6.0, -2.0);
	ecs_comp_add(ent, COMP_ANIM, 1, anim);
	ecs_comp_add(ent, COMP_COLLISION, 5, 12, 4, -6.0, -2.0, collflags);
	ecs_comp_add(ent, COMP_DIRECTION, 1, isRight);
	ecs_comp_add(ent, COMP_PROJECTILE, 0);
	return (ent);
}

uint32_t	entities_enemy(double x, double y)
{
	uint32_t		ent;
	uint32_t		collflags;

	collflags = (FLAG_ENEMIES);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_SPRITE, 3, ASSET_METROID_1, -8.0, -8.0);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_METROID);
	ecs_comp_add(ent, COMP_COLLISION, 5, 16, 16, -8.0, -8.0, collflags);
	ecs_comp_add(ent, COMP_AI, 0);
	return (ent);
}