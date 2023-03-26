/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 06:48:31 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

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

ent_id_t	entities_player(double x, double y)
{
	ent_id_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_CTRL, 0);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_GRAV, 1, 1.0);
	ecs_comp_add(ent, COMP_SPRITE, 4, ASSET_SAM_IDLE_R, -20.0, -40.0);
	ecs_comp_add(ent, COMP_COLLISION, 4, 16, 16, -8, -16);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_IDLE_R);
	ecs_comp_add(ent, COMP_STATE, 1, STATE_IDLE);
	ecs_comp_add(ent, COMP_DIRECTION, 0, true);
	return (ent);
}

ent_id_t	entities_collectible(double x, double y)
{
	ent_id_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	return (ent);
}
