/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:21:13 by evallee-         ###   ########.fr       */
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
}

uint32_t	entities_player(double x, double y)
{
	uint32_t		ent;
	uint32_t		collflags;
	
	collflags = (COLL_FLAG_WORLD | COLL_FLAG_PLAYER);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_CTRL, 0);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_GRAV, 1, 1.0);
	ecs_comp_add(ent, COMP_SPRITE, 4, ASSET_SAM_IDLE_R, -20.0, -40.0);
	ecs_comp_add(ent, COMP_COLLISION, 5, 16, 32, -8.0, -32.0, collflags);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_IDLE_R);
	ecs_comp_add(ent, COMP_STATE, 1, STATE_IDLE);
	ecs_comp_add(ent, COMP_DIRECTION, 1, true);
	return (ent);
}

uint32_t	entities_collectible(double x, double y)
{
	uint32_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	return (ent);
}
