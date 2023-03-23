/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:33:12 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/22 03:50:22 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "entities.h"

void	sys_controls(mlx_key_data_t keydata, void *params)
{
	(void)params;
	comp_ctrl_t	*ctrl;
	comp_vel_t	*vel;
	ent_id_t	ent;

	ent = 0;
	while (ent < ecs_num())
	{
		ctrl = ecs_comp_get(ent, COMP_CTRL);
		vel = ecs_comp_get(ent, COMP_VEL);
		if (ctrl && vel)
		{
			vel->curr.x = 0;
			if (keydata.key == MLX_KEY_A && keydata.action > 0)
				vel->curr.x = -50;
			if (keydata.key == MLX_KEY_D && keydata.action > 0)
				vel->curr.x = 50;
			if (keydata.key == MLX_KEY_SPACE && keydata.action > 0)
				vel->curr.y = -10;
		}
		ent++;
	}
}
