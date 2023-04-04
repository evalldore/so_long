/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:43:38 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:34:56 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"
#include "entities.h"

void	sys_projectiles(uint32_t ent, va_list args)
{
	t_c_project		*project;
	mlx_t			*mlx;

	mlx = va_arg(args, void *);
	project = ecs_comp_get(ent, COMP_PROJECTILE);
	if (!project)
		return ;
	project->time += mlx->delta_time;
	if (project->time > 0.3)
	{
		ecs_remove(ent);
	}
}

void	shoot(uint32_t	player)
{
	t_c_pos		*pos;
	t_c_dir		*dir;

	pos = ecs_comp_get(player, COMP_POS);
	dir = ecs_comp_get(player, COMP_DIRECTION);
	if (!pos || !dir)
		return ;
	entities_projectile(pos->curr.x, pos->curr.y - 24.0, dir->curr);
}
