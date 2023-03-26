/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:33:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 18:20:01 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "entities.h"

static void	set(ent_id_t ent, keys_t key, bool toggle)
{
	comp_ctrl_t		*ctrl;
	
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	if (key == MLX_KEY_A)
		ctrl->left = toggle;
	if (key == MLX_KEY_D)
		ctrl->right = toggle;
	if (key == MLX_KEY_W)
		ctrl->jump = toggle;
	if (key == MLX_KEY_SPACE)
		ctrl->shoot = toggle;
}

void	sys_controls(mlx_key_data_t keydata, void *params)
{
	ent_id_t		ent;

	ent = 0;
	(void)params;
	while (ent < ecs_num())
	{
		if (ecs_comp_get(ent, COMP_CTRL))
		{
			if (keydata.action == MLX_PRESS)
				set(ent, keydata.key, true);
			else if (keydata.action == MLX_RELEASE)
				set(ent, keydata.key, false);
		}
		ent++;
	}
}

static void	jump(ent_id_t	ent)
{
	comp_state_t	*state;
	comp_vel_t		*vel;
	comp_grav_t		*grav;

	state = ecs_comp_get(ent, COMP_STATE);
	vel = ecs_comp_get(ent, COMP_VEL);
	grav = ecs_comp_get(ent, COMP_GRAV);
	if (!state || !vel || !grav)
		return ;
	if (state && state->curr == STATE_JUMP)
		return ;
	vel->curr.y = -180;
	grav->scale = 0.0f;
}

static void	move(ent_id_t ent, float speed)
{
	comp_dir_t	*dir;
	comp_vel_t	*vel;

	dir = ecs_comp_get(ent, COMP_DIRECTION);
	vel = ecs_comp_get(ent, COMP_VEL);
	if (!dir || !vel)
		return ;
	if (speed > 0)
		dir->curr = true;
	else if (speed < 0)
		dir->curr = false;
	vel->curr.x = speed;
}

void	sys_controls_tick(double dt)
{
	ent_id_t	ent;
	comp_ctrl_t	*ctrl;

	ent = 0;
	(void)dt;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		if (ctrl)
		{
			move(ent, (-120 * ctrl->left) + (120 * ctrl->right));
			if (ctrl->jump)
				jump(ent);
		}
		ent++;
	}
}
