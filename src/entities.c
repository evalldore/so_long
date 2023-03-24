/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 18:42:27 by evallee-         ###   ########.fr       */
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
}

ent_id_t	entities_player(mlx_t *mlx, double x, double y)
{
	ent_id_t	ent;
	int32_t		inst;
	mlx_image_t	*img;

	img = assets_get(ASSET_SAM_IDLE);
	inst = mlx_image_to_window(mlx, img, x - 20.0, y - 40.0);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_CTRL, 0);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_GRAV, 1, 1.0);
	ecs_comp_add(ent, COMP_SPRITE, 4, ASSET_SAM_IDLE, inst, -20.0, -40.0);
	ecs_comp_add(ent, COMP_COLLISION, 4, 16, 16, -8, -16);
	ecs_comp_add(ent, COMP_ANIM, 1, ANIM_WALK);
	return (ent);
}

ent_id_t	entities_collectible(double x, double y)
{
	ent_id_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	return (ent);
}