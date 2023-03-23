/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:05:09 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 02:32:10 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "assets.h"

void	entities_init()
{
	comp_ctrl_reg();
	comp_pos_reg();
	comp_vel_reg();
	comp_grav_reg();
	comp_sprite_reg();
}

ent_id_t	entities_player(mlx_t *mlx, double x, double y)
{
	ent_id_t	ent;
	int32_t		inst;

	inst = mlx_image_to_window(mlx, assets_get(ASSET_SAM_IDLE), x - 20.0, y - 40.0);
	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	ecs_comp_add(ent, COMP_CTRL, 0);
	ecs_comp_add(ent, COMP_VEL, 2, 0.0, 0.0);
	ecs_comp_add(ent, COMP_GRAV, 1, 1.0);
	ecs_comp_add(ent, COMP_SPRITE, 4, ASSET_SAM_IDLE, inst, -20.0, -40.0);
	return (ent);
}

ent_id_t	entities_collectible(double x, double y)
{
	ent_id_t	ent;

	ent = ecs_create();
	ecs_comp_add(ent, COMP_POS, 2, x, y);
	return (ent);
}