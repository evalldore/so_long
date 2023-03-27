/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:33:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:21:13 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "entities.h"

static void	set(uint32_t ent, keys_t key, bool toggle)
{
	t_c_ctrl		*ctrl;
	
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	if (key == MLX_KEY_A)
		ctrl->left = toggle;
	if (key == MLX_KEY_D)
		ctrl->right = toggle;
	if (key == MLX_KEY_SPACE)
		ctrl->jump = toggle;
	if (key == MLX_KEY_ENTER)
		ctrl->shoot = toggle;
}

void	sys_controls(mlx_key_data_t keydata, void *params)
{
	uint32_t		ent;

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

static void	jump(uint32_t	ent)
{
	t_c_state	*state;
	t_c_vel		*vel;
	t_c_grav		*grav;

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

static void	move(uint32_t ent, float speed)
{
	t_c_dir	*dir;
	t_c_vel	*vel;

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
	uint32_t	ent;
	t_c_ctrl	*ctrl;

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
