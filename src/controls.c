/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:33:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 15:45:07 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "entities.h"

static void	pressed(ent_id_t ent, keys_t key)
{
	comp_ctrl_t	*ctrl;
	comp_vel_t	*vel;
	comp_grav_t	*grav;

	ctrl = ecs_comp_get(ent, COMP_CTRL);
	vel = ecs_comp_get(ent, COMP_VEL);
	grav = ecs_comp_get(ent, COMP_GRAV);
	if (key == MLX_KEY_A)
		ctrl->left = true;
	if (key == MLX_KEY_D)
		ctrl->right = true;
	if (key == MLX_KEY_SPACE)
	{
		ctrl->jump = true;
		vel->curr.y = -180;
		grav->scale = 0.0f;
	}
}

static void	released(ent_id_t ent, keys_t key)
{
	comp_ctrl_t	*ctrl;

	ctrl = ecs_comp_get(ent, COMP_CTRL);
	if (key == MLX_KEY_A)
		ctrl->left = false;
	if (key == MLX_KEY_D)
		ctrl->right = false;
	if (key == MLX_KEY_SPACE)
		ctrl->jump = false;
}

void	sys_controls(mlx_key_data_t keydata, void *params)
{
	ent_id_t	ent;

	ent = 0;
	(void)params;
	while (ent < ecs_num())
	{
		if (ecs_comp_get(ent, COMP_CTRL))
		{
			if (keydata.action == MLX_PRESS)
				pressed(ent, keydata.key);
			else if (keydata.action == MLX_RELEASE)
				released(ent, keydata.key);
		}
		ent++;
	}
}

void	sys_controls_tick(double dt)
{
	ent_id_t	ent;
	comp_ctrl_t	*ctrl;
	comp_vel_t	*vel;
	comp_grav_t	*grav;

	ent = 0;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		vel = ecs_comp_get(ent, COMP_VEL);
		grav = ecs_comp_get(ent, COMP_GRAV);
		if (grav)
		{
			grav->scale += dt * 3;
			if (grav->scale > 1)
				grav->scale = 1;
		}
		if (ctrl)
		{
			vel->curr.x = 0;
			if (ctrl->left)
				vel->curr.x += -120;
			if (ctrl->right)
				vel->curr.x += 120;
		}
		ent++;
	}
}
