/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:33:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:34:07 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "map.h"
#include "coordinates.h"
#include "interact.h"

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
	t_c_grav	*grav;

	state = ecs_comp_get(ent, COMP_STATE);
	vel = ecs_comp_get(ent, COMP_VEL);
	grav = ecs_comp_get(ent, COMP_GRAV);
	if (!state || !vel || !grav)
		return ;
	if (state && state->curr == STATE_JUMP)
		return ;
	vel->curr.y = -188;
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

void	sys_controls_tick(uint32_t ent, va_list args)
{
	t_c_ctrl	*ctrl;
	t_c_pos		*pos;
	t_c_state	*state;
	t_uvec		coords;

	(void)args;
	ctrl = ecs_comp_get(ent, COMP_CTRL);
	state = ecs_comp_get(ent, COMP_STATE);
	pos = ecs_comp_get(ent, COMP_POS);
	if (!ctrl)
		return ;
	move(ent, (-120 * ctrl->left) + (120 * ctrl->right));
	if (ctrl->jump && state->curr != STATE_JUMP)
	{
		coords = pos_to_coords(pos->curr.x, pos->curr.y);
		if (map_get().data[coords.y][coords.x] == '1')
			jump(ent);
	}
	if (ctrl->lastshoot != ctrl->shoot)
	{
		ctrl->lastshoot = ctrl->shoot;
		if (ctrl->shoot)
			shoot(ent);
	}
}
